#include "stdafx.h"
#include "kcountdownbutton.h"

KCountdownButton::KCountdownButton(QWidget *parent)
    : QPushButton(parent)
{
    connect(&t_, &QTimer::timeout, [&](){
        if (countdown_-- > 0){
            setText(txt_ + QStringLiteral("(%1)").arg(countdown_));
        }
        else{
            setEnabled(true);
            setText(txt_);
            t_.stop();
        }
    });

    connect(this, &QPushButton::clicked, [&](){
        setEnabled(false);
        txt_ = text();
        countdown_ = secs_;
        setText(txt_ + QStringLiteral("(%1)").arg(countdown_));

        // 设定定时器，倒计时
        t_.start(1000);
    });
}

KCountdownButton::~KCountdownButton()
{
}

void KCountdownButton::stopCountdown()
{
    countdown_ = 0;
}
