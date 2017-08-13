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
    enum DISPLAY
    {
        DISPLAY_MS = 0X01,
        DISPLAY_S  = 0X02,
        DISPLAY_M  = 0X04,
        DISPLAY_H  = 0X08
    };
    explicit Clock(QWidget *parent = 0);
    explicit Clock(uchar display, QWidget *parent = 0);

    uchar getDisplayType();
public slots:
    void setDisplay(uchar display);

signals:
    void displayTypeUpdated(Clock* clock);
    void displayTypeUpdated(uchar display);
    void displayTypeUpdated();

private:
    QGridLayout* layout_;
    AnalogClock* analog_clock_;
    DigitalClock* digital_clock_;
    uchar displayType_;
};

#endif // CLOCK_H
