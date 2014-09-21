#include "MainWindow.h"

#include <iostream>

int main(int argc, char** argv) {
  srand(time(NULL));  // init rand;

  QApplication app(argc, argv);

  QFontDatabase::addApplicationFont("../PieceOfCake/fonts/edosz.ttf");
  QFontDatabase::addApplicationFont("../PieceOfCake/fonts/watermark.ttf");

  MainWindow window;
  window.show();

  return app.exec();
}
