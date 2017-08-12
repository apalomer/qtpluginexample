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
    DigitalClock(QWidget *parent = 0);
    ~DigitalClock();

private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
