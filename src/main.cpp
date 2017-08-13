#include <QApplication>
#include "clock/clock.h"
#include "clockversion.h"

int main(int argc, char** argv)
{

    // Create application
    QApplication app(argc, argv);

    // Create widget
    Clock* clock = new Clock;
    clock->show();

    // Display clock version
    printf("This is clock version %s\n", CLOCK_VERSION_STRING);

    // Run
    return app.exec();
}
