#include "MainWindow.h"

#include <QAction>

MainWindow::MainWindow(QWidget* parent):
  QMainWindow(parent),
  _fractalRendererController(1000) {

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

  for (unsigned int k = 0; k < nextRandomPoints.size(); ++k) {
    const Point2d& curPoint = FractalRendererController::homothetie(nextRandomPoints.at(k));
    _fractalRendererWidget->drawPixel(curPoint.getX(), curPoint.getY());
  }
  _fractalRendererWidget->update();
}
