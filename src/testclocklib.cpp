
#include "testclocklib.h"

int testClockLib(int argc, char** argv)
{
    // Create application
    QApplication app(argc,argv);

    // Create widget
    Clock* clock = new Clock;
    clock->show();

    // Display clock version
    printf("This is clock version %s\n", CLOCK_VERSION_STRING);

    // Run
    return app.exec();
}
