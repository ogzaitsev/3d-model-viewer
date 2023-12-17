#ifndef CPP4_3DVIEWER_V2_3DVIEWER_VIEW_SCENE_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_VIEW_SCENE_H_

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

#include "../model/Data3D.h"

namespace ogzaitsev {

class Scene : public QOpenGLWidget {
  Q_OBJECT
 private:
  std::shared_ptr<ogzaitsev::Data3D> data;

 public:
  explicit Scene(QWidget* parent = NULL);
  Scene();
  void initializeGL();
  void resizeGL(int h, int w);
  void paintGL();
  void setData(std::shared_ptr<ogzaitsev::Data3D> data);

 public:
  struct Preferences {
    bool parallel = true;
    bool central = false;
    bool solidLine = true;
    bool dashedLine = false;
    bool noVertices = true;
    bool circledVertices = false;
    bool squaredVertices = true;
    float lineColorR = 0.95;
    float lineColorG = 0.94;
    float lineColorB = 0.95;
    float vertexColorR = 0.96;
    float vertexColorG = 0.47;
    float vertexColorB = 0;
    float backColorR = 0.24;
    float backColorG = 0.23;
    float backColorB = 0.23;
    int lineWidth = 1;
    int vertexSize = 5;
  };
  Preferences preferences;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_3DVIEWER_VIEW_SCENE_H_
