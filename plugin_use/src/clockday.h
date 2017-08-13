#ifndef CLOCKDAY_H
#define CLOCKDAY_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class ClockDay;
}

class ClockDay : public QWidget
{
    Q_OBJECT

public:
    explicit ClockDay(QWidget *parent = 0);
    ~ClockDay();
private slots:
    void updateDay();
private:
    Ui::ClockDay *ui;
    QTimer* timer;
};

#endif // CLOCKDAY_H
