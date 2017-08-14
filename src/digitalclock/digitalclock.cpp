#include "digitalclock.h"

DigitalClock::DigitalClock(uchar display, QWidget *parent)
    : QLCDNumber(parent), displayType_(display)
{
    // Preapare widget
    setWindowTitle(tr("Digital Clock"));

    // Set Widget style
    setSegmentStyle(Filled);

    // Set timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1);

    // Draw
    showTime();

}

DigitalClock::DigitalClock(QWidget *parent)
    : DigitalClock(DISPLAY_H|DISPLAY_M|DISPLAY_S,parent)
{

}

DigitalClock::~DigitalClock()
{

}

void DigitalClock::showTime()
 {
    // Get time
     QTime time = QTime::currentTime();

     // Covnert to sting
     int step(250);
     QString text("");
     if (displayType_ & DISPLAY_H)
         text += time.toString("HH");
     if (displayType_ & DISPLAY_M)
     {
         if (displayType_ & DISPLAY_H){
             if ((time.msec() / step)%2 == 0)
                text += ":";
             else
                text += " ";
         }
         text += time.toString("mm");
     }
     if (displayType_ & DISPLAY_S)
     {
         if (displayType_ & DISPLAY_M || displayType_ & DISPLAY_H){
             if ((time.msec() / step)%2 == 0)
                text += ":";
             else
                text += " ";
         }
         text += time.toString("ss");
     }
     if (displayType_ & DISPLAY_MS)
     {
         if (displayType_ & DISPLAY_S || displayType_ & DISPLAY_M || displayType_ & DISPLAY_H)
             text += ".";
         text += time.toString("zzz");
     }

     // Set up display
     setNumDigits(text.size());
     display(text);
 }

void DigitalClock::setDisplay(uchar display)
{
    displayType_ = display;
    emit displayTypeUpdated();
    emit displayTypeUpdated(display);
    emit displayTypeUpdated(this);
}

uchar DigitalClock::getDisplayType()
{
    return displayType_;
}

bool DigitalClock::getDisplayHours()
{
    return displayType_ & DISPLAY_H;
}

bool DigitalClock::getDisplayMinutes()
{
    return displayType_ & DISPLAY_M;
}

bool DigitalClock::getDisplaySeconds()
{
    return displayType_ & DISPLAY_S;
}

bool DigitalClock::getDisplayMilliseconds()
{
    return displayType_ & DISPLAY_MS;
}

void DigitalClock::setDisplayHours(bool display)
{
    if (display)
        addDisplay(DISPLAY_H);
    else
        removeDisplay(DISPLAY_H);
}

void DigitalClock::setDisplayMinutes(bool display)
{
    if (display)
        addDisplay(DISPLAY_M);
    else
        removeDisplay(DISPLAY_M);
}

void DigitalClock::setDisplaySeconds(bool display)
{
    if (display)
        addDisplay(DISPLAY_S);
    else
        removeDisplay(DISPLAY_S);
}

void DigitalClock::setDisplayMilliseconds(bool display)
{
    if (display)
        addDisplay(DISPLAY_MS);
    else
        removeDisplay(DISPLAY_MS);
}

void DigitalClock::addDisplay(uchar display)
{
    displayType_ |= display;
    emit displayTypeUpdated();
    emit displayTypeUpdated(displayType_);
    emit displayTypeUpdated(this);
}

void DigitalClock::removeDisplay(uchar display)
{
    displayType_ &= ~(1u<<(int)log2(display));
    emit displayTypeUpdated();
    emit displayTypeUpdated(displayType_);
    emit displayTypeUpdated(this);
}
