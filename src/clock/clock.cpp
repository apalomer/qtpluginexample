#include "clock.h"

Clock::Clock(QWidget *parent) :
    Clock(DISPLAY_H|DISPLAY_M|DISPLAY_S,parent)
{

}

Clock::Clock(uchar display, QWidget *parent):
    QWidget(parent), displayType_(display)
{
    // Set window title
    this->setWindowTitle("Clock");
    this->resize(200,250);

    // Create the image widget
    analog_clock_ = new AnalogClock();
    connect(this,SIGNAL(displayTypeUpdated(uchar)),analog_clock_,SLOT(setDisplay(uchar)));

    // Create digital clock
    digital_clock_ = new DigitalClock();
    connect(this,SIGNAL(displayTypeUpdated(uchar)),digital_clock_,SLOT(setDisplay(uchar)));

    // Set layout
    layout_ = new QGridLayout;
    layout_->addWidget(analog_clock_,0,0,4,4);
    layout_->addWidget(digital_clock_,4,0,1,4);
    this->setLayout(layout_);
}

void Clock::setDisplay(uchar display)
{
    displayType_ = display;
    emit displayTypeUpdated();
    emit displayTypeUpdated(display);
    emit displayTypeUpdated(this);
}

uchar Clock::getDisplayType()
{
    return displayType_;
}

