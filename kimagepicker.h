#pragma once

#include <QLabel>

class KImagePicker : public QLabel
{
    Q_OBJECT

public:
    KImagePicker(QWidget *parent);
    ~KImagePicker();

    QString path()const {
        return path_;
    }

    void setPath(const QString& path);

protected:
    virtual void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

private:
    QString path_;
};
