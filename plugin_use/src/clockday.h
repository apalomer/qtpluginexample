#ifndef CLOCKDAY_H
#define CLOCKDAY_H

#include <QDateTime>
#include <QTimer>
#include <QWidget>

namespace Ui
{
class ClockDay;
}

class ClockDay : public QWidget
{
  Q_OBJECT

public:
  explicit ClockDay(QWidget *parent = nullptr);
  ~ClockDay();
public slots:
  void updateComboBox();
private slots:
  void updateDay();

private:
  Ui::ClockDay *ui;
  QTimer *timer;
};
#endif  // CLOCKDAY_H
