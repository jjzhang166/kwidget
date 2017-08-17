#include "stdafx.h"
#include "kimagepicker.h"
#include <QFileDialog>

KImagePicker::KImagePicker(QWidget *parent)
    : QLabel(QStringLiteral("请点击选择图片"), parent)
{
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Raised);
    setScaledContents(true);
}

KImagePicker::~KImagePicker()
{
}

void KImagePicker::mousePressEvent(QMouseEvent *ev) 
{
    path_ = QFileDialog::getOpenFileName(this->window(), 
        QStringLiteral("请选择图象文件"), "", "Image (*.jpg *.gif *.png)");
    if (!path_.isEmpty()) {
        QPixmap pic;
        if (pic.load(path_)) {
            setPixmap(pic);
        }
        else {
            setText(QStringLiteral("无效的图片！"));
            path_ = "";
        }
    }
}
