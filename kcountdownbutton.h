#pragma once

#include <QPushButton>
#include <QTimer>

class KCountdownButton : public QPushButton
{
    Q_OBJECT

public:
    KCountdownButton(QWidget *parent);
    ~KCountdownButton();

    void setCountdown(int secs){
        secs_ = secs;
    }

    void stopCountdown();

private:
    int secs_ = 3;
    int countdown_ = 0;
    QString txt_;
    QTimer t_;
};
