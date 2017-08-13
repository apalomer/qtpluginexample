#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QDebug>

class DigitalClock : public QLCDNumber
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
    DigitalClock(QWidget *parent = 0);
    DigitalClock(uchar display, QWidget *parent = 0);
    ~DigitalClock();

    uchar getDisplayType();

public slots:
    void setDisplay(uchar display);

signals:
    void displayTypeUpdated(DigitalClock* digital_clock);
    void displayTypeUpdated(uchar display);
    void displayTypeUpdated();

private slots:
    void showTime();
private:
    uchar displayType_;
};

#endif // DIGITALCLOCK_H
