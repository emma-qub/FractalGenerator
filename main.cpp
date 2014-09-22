#include "MainWindow.h"

#include <iostream>
#include <ctime>

#include <QApplication>

int main(int argc, char** argv) {
  srand(time(NULL));  // init rand;

  QApplication app(argc, argv);

  MainWindow window;
  window.show();

  return app.exec();
}
