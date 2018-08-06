#include <clockversion.h>
#include <stdio.h>
#include <QApplication>
#include "clockday.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  // Create the image widget
  ClockDay* cd = new ClockDay();

  // Run
  printf("This ClockDay is using clock version %s\n", CLOCK_VERSION_STRING);
  cd->show();
  return app.exec();
}
