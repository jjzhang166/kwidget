#include "stdafx.h"
#include "kimagepicker.h"
#include <QFileDialog>

KImagePicker::KImagePicker(QWidget *parent)
    : QLabel(QStringLiteral("����ѡ��ͼƬ"), parent)
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
        QStringLiteral("��ѡ��ͼ���ļ�"), "", "Image (*.jpg *.gif *.png)");
    if (!path_.isEmpty()) {
        QPixmap pic;
        if (pic.load(path_)) {
            setPixmap(pic);
        }
        else {
            setText(QStringLiteral("��Ч��ͼƬ��"));
            path_ = "";
        }
    }
}
