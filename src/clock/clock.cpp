#include "clock.h"

Clock::Clock(QWidget *parent) :
    QWidget(parent)
{
    // Set window title
    this->setWindowTitle("Clock");
    this->resize(200,250);

    // Create the image widget
    analog_clock_ = new AnalogClock();

    // Create digital clock
    digital_clock_ = new DigitalClock();

    // Set layout
    layout_ = new QGridLayout;
    layout_->addWidget(analog_clock_,0,0,4,4);
    layout_->addWidget(digital_clock_,4,0,1,4);
    this->setLayout(layout_);
}
