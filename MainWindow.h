#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "FractalRendererWidget.h"
#include "FractalRendererController.h"

class MainWindow: public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget* parent = NULL);

public slots:
  void drawNextStep(void);

private:
  FractalRendererWidget* _fractalRendererWidget;
  FractalRendererController _fractalRendererController;
};

#endif // MAINWINDOW_H
