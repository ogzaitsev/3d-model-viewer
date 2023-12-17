#include "Facade.h"

#include "../model/TransformContext.h"

namespace ogzaitsev {

std::string Facade::openFileAndDraw(std::string filename) {
  try {
    dataBuilder.setFile(filename);
  } catch (std::runtime_error const& e) {
    return e.what();
  }

  scene->setData(dataBuilder.setData().getData());
  scene->update();
  std::string result(
      "vertices: " +
      std::to_string(dataBuilder.getData().get()->getPointArrayLength() / 3) +
      " | edges: " +
      std::to_string(dataBuilder.getData().get()->getIndexArrayLength() / 4) +
      " | " + filename);
  resetState();
  return result;
}

void Facade::moveObject(double value, char axes) {
  TransformContext context(std::make_unique<MoveStrategy>());
  MoveStrategy::transform_t type = MoveStrategy::xAxes;
  if (axes == 'x') {
    value -= xPos;
    xPos += value;
    type = MoveStrategy::xAxes;
  } else if (axes == 'y') {
    value -= yPos;
    yPos += value;
    type = MoveStrategy::yAxes;
  } else if (axes == 'z') {
    value -= zPos;
    zPos += value;
    type = MoveStrategy::zAxes;
  }
  context.transform(dataBuilder.getData(), value, type);
  scene->update();
}

void Facade::rotateObject(double angle, char axes) {
  TransformContext context(std::make_unique<RotateStrategy>());
  RotateStrategy::transform_t type = RotateStrategy::xAxes;
  if (axes == 'x') {
    angle -= xAngle;
    xAngle += angle;
    type = RotateStrategy::xAxes;
  } else if (axes == 'y') {
    angle -= yAngle;
    yAngle += angle;
    type = RotateStrategy::yAxes;
  } else if (axes == 'z') {
    angle -= zAngle;
    zAngle += angle;
    type = RotateStrategy::zAxes;
  }
  angle *= M_PI / 180;
  context.transform(dataBuilder.getData(), angle, type);
  scene->update();
}

void Facade::scaleObject(double ratio) {
  TransformContext context(std::make_unique<ScaleStrategy>());
  if (ratio > 0)
    context.transform(dataBuilder.getData(), ratio / currentZoom,
                      ScaleStrategy::zoomIn);
  if (ratio < 0) {
    context.transform(dataBuilder.getData(), ratio * (-1) / currentZoom,
                      ScaleStrategy::zoomOut);
  }
  currentZoom = std::fabs(ratio);
  scene->update();
}

void Facade::resetState() {
  xPos = 0;
  yPos = 0;
  zPos = 0;
  xAngle = 0;
  yAngle = 0;
  zAngle = 0;
  currentZoom = 1;
}

}  // namespace s21
