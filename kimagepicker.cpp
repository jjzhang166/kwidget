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

void KImagePicker::setPath(const QString& path)
{
    QPixmap pic;
    if (pic.load(path)) {
        path_ = path;
        setPixmap(pic);
    }
    else {
        setText(QStringLiteral("��Ч��ͼƬ��"));
        path_ = "";
    }
}

void KImagePicker::mousePressEvent(QMouseEvent *ev)
{
    path_ = QFileDialog::getOpenFileName(this->window(), 
        QStringLiteral("��ѡ��ͼ���ļ�"), "", "Image (*.jpg *.gif *.png)");
    if (!path_.isEmpty()) {
        setPath(path_);
    }
}
