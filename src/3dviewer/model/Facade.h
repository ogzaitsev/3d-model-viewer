#ifndef CPP4_3DVIEWER_V2_3DVIEWER_MODEL_FACADE_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_MODEL_FACADE_H_

#include <QCoreApplication>
#include <QFile>
#include <QTimer>

#include "../model/DataBuilder.h"
#include "../view/Scene.h"

namespace ogzaitsev {

//! Facade is a structural design pattern that provides a simplified interface
/*!
 * A facade is a class that provides a simple interface to a complex subsystem
 *  which contains lots of moving parts.
 *  A facade might provide limited functionality in comparison to working
 *  with the subsystem directly.
 *  However, it includes only those features that clients really care about.
 */
class Facade {
 private:
  DataBuilder dataBuilder;
  Scene *scene;
  double xPos = 0;
  double yPos = 0;
  double zPos = 0;
  double xAngle = 0;
  double yAngle = 0;
  double zAngle = 0;
  double currentZoom = 1;

  void resetState();

 public:
  Facade(ogzaitsev::Scene *scene) : scene(scene) {}
  std::string openFileAndDraw(std::string filename);
  void moveObject(double value, char axes);
  void rotateObject(double value, char axes);
  void scaleObject(double ratio);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_MODEL_FACADE_H_
