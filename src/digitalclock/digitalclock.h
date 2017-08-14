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
    Q_PROPERTY(bool Hours READ getDisplayHours WRITE setDisplayHours)
    Q_PROPERTY(bool Minutes READ getDisplayMinutes WRITE setDisplayMinutes)
    Q_PROPERTY(bool Seconds READ getDisplaySeconds WRITE setDisplaySeconds)
    Q_PROPERTY(bool Milliseconds READ getDisplayMilliseconds WRITE setDisplayMilliseconds)
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
    bool getDisplayHours();
    bool getDisplayMinutes();
    bool getDisplaySeconds();
    bool getDisplayMilliseconds();

public slots:
    void addDisplay(uchar display);
    void removeDisplay(uchar display);
    void setDisplay(uchar display);
    void setDisplayHours(bool display);
    void setDisplayMinutes(bool display);
    void setDisplaySeconds(bool display);
    void setDisplayMilliseconds(bool display);

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
