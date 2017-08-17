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

protected:
    virtual void mousePressEvent(QMouseEvent *ev) Q_DECL_OVERRIDE;

private:
    QString path_;
};
