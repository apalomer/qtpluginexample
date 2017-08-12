#include <QApplication>
#include "clock.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    // Create the image widget
    Clock* clock = new Clock();

    // Run
    clock->show();
    return app.exec();
}
