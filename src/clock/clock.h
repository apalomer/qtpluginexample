#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QGridLayout>

#include "abstractclock/abstractclock.h"
#include "analogclock/analogclock.h"
#include "digitalclock/digitalclock.h"

class Clock : public AbstractClock
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);
    explicit Clock(uchar display, QWidget *parent = nullptr);
    ~Clock();

private:
    QGridLayout* layout_;
    AnalogClock* analog_clock_;
    DigitalClock* digital_clock_;
};

#endif // CLOCK_H
