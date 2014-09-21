#include "FractalRendererController.h"

#include <cstdlib> // rand
#include <cmath> // floor

FractalRendererController::FractalRendererController(unsigned int pointsCount, int xmin, int xmax, int ymin, int ymax):
  _pointsCount(pointsCount),
  _randomPoints() {

  for (unsigned int k = 0; k < _pointsCount; ++k) {
    Point2d randomPoint(xmin, xmax, ymin, ymax);
    _randomPoints.push_back(randomPoint);
    _lastRandomPoints.push_back(randomPoint);
  }
}

FractalRendererController::~FractalRendererController(void) {
}

unsigned int FractalRendererController::pointsCount(void) const
{
  return _pointsCount;
}

void FractalRendererController::setPointsCount(unsigned int pointsCount)
{
  _pointsCount = pointsCount;
}

std::vector<Point2d> FractalRendererController::randomPoints() const
{
  return _randomPoints;
}

std::vector<Point2d> FractalRendererController::subRandomPoints(int beginStep, int stepCount) const {
  std::vector<Point2d> result;

  unsigned int firstIndex = beginStep*_pointsCount;
  unsigned int lastIndex = firstIndex + stepCount*_pointsCount;

  for (unsigned int k = firstIndex; k < lastIndex; ++k)
    result.push_back(_randomPoints.at(k));

  return result;
}

std::vector<Point2d> FractalRendererController::computeNextStep(void) {
  std::vector<Point2d> result;

  for (unsigned int k = 0; k < _pointsCount; ++k) {
    int choice = std::rand()%3;
    std::cerr << choice << std::endl;
    Point2d newPoint(applyTransformation(_lastRandomPoints.at(k), choice));

    result.push_back(newPoint);
    _randomPoints.push_back(newPoint);

    std::cerr << newPoint << std::endl;
  }

  _lastRandomPoints.clear();
  _lastRandomPoints = result;

  return result;
}

Point2d FractalRendererController::applyTransformation(const Point2d& point, int operationChoice) const {
  int x = point.getX();
  int y = point.getY();
  int newX = x/2;
  int newY = y/2;

  if (operationChoice == 1) {
    newX = (x+1)/2;
  } else if (operationChoice == 2) {
    newY = (y+1)/2;
  }

  return Point2d(newX, newY);
}
