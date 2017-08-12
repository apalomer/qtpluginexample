#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include "analogclock.h"
#include "digitalclock.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    // Create the image widget
    AnalogClock* ac = new AnalogClock();

    // Create digital clock
    DigitalClock* dc = new DigitalClock();

    // Create Window
    QMainWindow* window = new QMainWindow;
    window->setWindowTitle("Clock");
    window->resize(200,200);

    // Create Widget
    QWidget* widget = new QWidget;
    window->setCentralWidget(widget);

    // Set layout
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(ac,0,0,4,4);
    layout->addWidget(dc,4,0,1,4);
    widget->setLayout(layout);

    // Run
    window->show();
    return app.exec();
}
