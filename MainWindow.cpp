#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent):
  QMainWindow(parent),
  _fractalRendererController(3) {

  _fractalRendererWidget = new FractalRendererWidget;
  setCentralWidget(_fractalRendererWidget);

  QAction* cleanAction = new QAction(this);
  cleanAction->setShortcut(QKeySequence::New);
  addAction(cleanAction);
  connect(cleanAction, SIGNAL(triggered()), _fractalRendererWidget, SLOT(clearImage()));

  QAction* nextStepAction = new QAction(this);
  nextStepAction->setShortcut(QKeySequence("CTRL+G"));
  addAction(nextStepAction);
  connect(nextStepAction, SIGNAL(triggered()), this, SLOT(drawNextStep()));
}

void MainWindow::drawNextStep(void) {
  std::vector<Point2d> nextRandomPoints(_fractalRendererController.computeNextStep());

  for (const Point2d& curPoint: nextRandomPoints) {
    _fractalRendererWidget->drawPixel(curPoint.getX(), curPoint.getY());
  }
  _fractalRendererWidget->update();
}
