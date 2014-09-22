#include "FractalRendererController.h"

#include <cstdlib> // rand
#include <cmath> // floor

FractalRendererController::FractalRendererController(unsigned int pointsCount):
  _pointsCount(pointsCount),
  _randomPoints() {

  for (unsigned int k = 0; k < _pointsCount; ++k) {
    Point2d randomPoint(-1, 1, -1, 1);
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
    Point2d newPoint(applyTransformation(_lastRandomPoints.at(k), choice));

    result.push_back(newPoint);
    _randomPoints.push_back(newPoint);
  }

  _lastRandomPoints.clear();
  _lastRandomPoints = result;

  return result;
}

Point2d FractalRendererController::applyTransformation(const Point2d& point, int operationChoice) const {
  float x = point.getX();
  float y = point.getY();
  float newX = x/2.f;
  float newY = y/2.f;

  if (operationChoice == 1) {
    newX = (x+1)/2;
  } else if (operationChoice == 2) {
    newY = (y+1)/2;
  }

  return Point2d(newX, newY);
}

Point2d FractalRendererController::homothetie(const Point2d& point, int xmin, int xmax, int ymin, int ymax) {
  return Point2d((point.getX()+1)*(xmax - xmin)/2, (point.getY()+1)*(ymax - ymin)/2);
}
