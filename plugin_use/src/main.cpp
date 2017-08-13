#include <QApplication>
#include "clockday.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    // Create the image widget
    ClockDay* cd = new ClockDay();

    // Run
    cd->show();
    return app.exec();
}
