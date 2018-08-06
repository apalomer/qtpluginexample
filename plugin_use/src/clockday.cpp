#include "clockday.h"
#include <bitset>
#include "ui_clockday.h"

ClockDay::ClockDay(QWidget *parent) : QWidget(parent), ui(new Ui::ClockDay)
{
  // Set up current widget
  ui->setupUi(this);

  // Create timer
  timer = new QTimer;
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateDay()));

  // Update widget
  updateDay();
}

ClockDay::~ClockDay()
{
  delete ui;
  delete timer;
}

void ClockDay::updateDay()
{
  QDateTime datetime = QDateTime::currentDateTime();
  ui->dayLabel->setText(datetime.toString("dddd dd/MM/yyyy"));

  // Connections
  //  connect(ui->hours_checkbox, &QCheckBox::clicked, this, &ClockDay::updateComboBox);
  //  connect(ui->minutes_checkbox, &QCheckBox::clicked, this, &ClockDay::updateComboBox);
  //  connect(ui->seconds_checkbox, &QCheckBox::clicked, this, &ClockDay::updateComboBox);
  //  connect(ui->milliseconds_checkbox, &QCheckBox::clicked, this, &ClockDay::updateComboBox);
}

void ClockDay::updateComboBox()
{
  std::cout << "Type: " << std::bitset<8>(ui->clock->getDisplayType());
  std::cout << " -> " << std::bitset<8>(ui->clock->getDisplayType()) << std::endl;
}
