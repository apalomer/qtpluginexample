#include "clockday.h"
#include "ui_clockday.h"

ClockDay::ClockDay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClockDay)
{
    // Set up current widget
    ui->setupUi(this);

    // Update clock style
    ui->comboBox->setCurrentIndex(3);

    // Create timer
    timer = new QTimer;
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDay()));

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
}

void ClockDay::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
        ui->clock->setDisplay(Clock::DISPLAY_H);
    if (index == 1)
        ui->clock->setDisplay(Clock::DISPLAY_H|Clock::DISPLAY_M);
    if (index == 2)
        ui->clock->setDisplay(Clock::DISPLAY_H|Clock::DISPLAY_M|Clock::DISPLAY_S);
    if (index == 3)
        ui->clock->setDisplay(Clock::DISPLAY_H|Clock::DISPLAY_M|Clock::DISPLAY_S|Clock::DISPLAY_MS);
    if (index == 4)
        ui->clock->setDisplay(Clock::DISPLAY_M|Clock::DISPLAY_S);
    if (index == 5)
        ui->clock->setDisplay(Clock::DISPLAY_M|Clock::DISPLAY_S|Clock::DISPLAY_MS);
    if (index == 6)
        ui->clock->setDisplay(Clock::DISPLAY_S);
    if (index == 7)
        ui->clock->setDisplay(Clock::DISPLAY_S|Clock::DISPLAY_MS);
}
