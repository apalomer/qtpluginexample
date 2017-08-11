#include <QApplication>
#include "analogclock.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    // Create the image widget
    AnalogClock* ac = new AnalogClock();
    ac->resize(300,300);

    // Run
    ac->show();
    return app.exec();
}
