#include "clockday.h"
#include "ui_clockday.h"

ClockDay::ClockDay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClockDay)
{
    ui->setupUi(this);

    // Create timer
    timer = new QTimer;
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDay()));
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
