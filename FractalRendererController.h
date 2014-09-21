#ifndef FRACTALRENDERERCONTROLLER_H
#define FRACTALRENDERERCONTROLLER_H

#include <vector>

#include "Point2d.h"

class FractalRendererController {

public:
  FractalRendererController(unsigned int pointsCount = 3, int xmin = 0, int xmax = 1280, int ymin = 0, int ymax = 900);
  virtual ~FractalRendererController(void);

  unsigned int pointsCount(void) const;
  void setPointsCount(unsigned int pointsCount);

  std::vector<Point2d> randomPoints(void) const;
  std::vector<Point2d> subRandomPoints(int beginStep, int stepCount) const;

  std::vector<Point2d> computeNextStep(void);
  Point2d applyTransformation(const Point2d& point, int operationChoice) const;

private:
  unsigned int _pointsCount;
  std::vector<Point2d> _randomPoints;
  std::vector<Point2d> _lastRandomPoints;

};

#endif // FRACTALRENDERERCONTROLLER_H
