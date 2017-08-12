#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setNumDigits(12);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1);

    showTime();

    setWindowTitle(tr("Digital Clock"));
}

DigitalClock::~DigitalClock()
{

}

void DigitalClock::showTime()
 {
     QTime time = QTime::currentTime();
     int step(250);
     QString text = time.toString("HH:mm:ss.zzz");
     if ((time.msec() / step)%2 == 0)
     {
         text[2] = ' ';
         text[5] = ' ';
     }
     display(text);
 }
