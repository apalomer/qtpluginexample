#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QVBoxLayout>
#include "abstractclock/abstractclock.h"

class DigitalClock : public AbstractClock
{
    Q_OBJECT
public:
    DigitalClock(QWidget *parent = nullptr);
    DigitalClock(uchar display, QWidget *parent = nullptr);
    ~DigitalClock();

private slots:
    void showTime();
private:
    QTimer* timer_;
    QLCDNumber* lcd_;
    QVBoxLayout* layout_;
};

#endif // DIGITALCLOCK_H
