#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QGridLayout>

#include "analogclock/analogclock.h"
#include "digitalclock/digitalclock.h"

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = 0);
private:
    QGridLayout* layout_;
    AnalogClock* analog_clock_;
    DigitalClock* digital_clock_;
};

#endif // CLOCK_H
