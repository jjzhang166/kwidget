#pragma once

#include <QLabel>
#include <QNetworkReply>

class KImagePicker : public QLabel
{
    Q_OBJECT

public:
	enum ImageMode {
		ImageModeLocalFile = 0x1,
		ImageModeWebFile = 0x2,
	};

    KImagePicker(QWidget *parent);
    ~KImagePicker();

    inline QString source()const {
        return source_;
    }

	void setImage(const QString& path);

	void setImageMode(int imgmode) {
		image_mode_ = imgmode;
	}

protected:
    virtual void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

	// 不修改source/path，仅加载显示图片
	void setLocalImage(const QString& path);

protected slots:
	void onDownload(int evt, QUrl, int progress, QNetworkReply::NetworkError);

private:
	int image_mode_ = 0xFF;
	QString source_;
    QString path_;
};
