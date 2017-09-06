#include "stdafx.h"
#include "kimagepicker.h"
#include "kutil/misc.h"
#include <QFileDialog>
#include <QMouseEvent>
#include <QInputDialog>
#include "knet/net.h"

KImagePicker::KImagePicker(QWidget *parent)
    : QLabel(QStringLiteral("鼠标左右键点选"), parent)
{
    setFrameShape(QFrame::Box);
    setFrameShadow(QFrame::Raised);
    setScaledContents(true);
}

KImagePicker::~KImagePicker()
{
}

void KImagePicker::setImage(const QString& path)
{
	if (source_ == path) {
		return;
	}
	source_ = path;

	if (path.startsWith("http://", Qt::CaseInsensitive)
		|| path.startsWith("https://", Qt::CaseInsensitive)) {
		// 先下载图片
		path_ = kutil::randomTempFileName();
		setText(QStringLiteral("正在下载图片！"));
		net::KHttpDownload(QUrl(path), path_, this,
			SLOT(onDownload(int, QUrl, int, QNetworkReply::NetworkError)));
	}
	else {
		path_ = path;
		setLocalImage(path_);
	}
}

void KImagePicker::mousePressEvent(QMouseEvent *ev)
{
	QString path;
	switch (ev->button())
	{
	case Qt::LeftButton:
	{
		if (image_mode_ & ImageModeLocalFile) {
			path = QFileDialog::getOpenFileName(this->window(),
				QStringLiteral("请选择图象文件"), path_, "Image (*.jpg *.gif *.png)");
		}
	}break;

	case Qt::RightButton:
	{
		if (image_mode_ & ImageModeWebFile) {
			path = QInputDialog().getText(this, QStringLiteral("请输入网络图片地址："),
				QStringLiteral("请输入网络图片地址"), QLineEdit::Normal, source_);
		}
	}break;
	}

	if (!path.isEmpty()) {
		setImage(path);
	}
}

void KImagePicker::setLocalImage(const QString& path)
{
	QPixmap pic;
	if (pic.load(path)) {
		setPixmap(pic);
	}
	else {
		setText(QStringLiteral("无效的图片！"));
		path_ = "";
	}
}

void KImagePicker::onDownload(int evt, QUrl, int progress, QNetworkReply::NetworkError err)
{
	if (net::HttpDownload_Event_Finished == evt) {
		setLocalImage(path_);
	}
}
