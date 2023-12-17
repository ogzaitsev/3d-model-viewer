#include "Scene.h"

namespace ogzaitsev {

Scene::Scene(QWidget* parent) : QOpenGLWidget{parent} {}

void Scene::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glScalef(0.25, 0.25, 0.25);
  glLineStipple(1, 0x00F0);
}

void Scene::resizeGL(int h, int w) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
}

void Scene::setData(std::shared_ptr<Data3D> data) { this->data = data; }

void Scene::paintGL() {
  glLoadIdentity();

  glClearColor(preferences.backColorR, preferences.backColorG,
               preferences.backColorB, 0);  // background color

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (preferences.parallel) {
    glOrtho(-2.5, 2.5, -2.5, 2.5, -50, 50);  // parallel projection
  } else {
    glFrustum(-0.8, 0.8, -0.8, 0.8, 0.9, 5);  // central projection
    glTranslated(0, 0, -2.5);
  }

  glLineWidth(preferences.lineWidth);

  if (preferences.dashedLine) {
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  glPointSize(preferences.vertexSize);

  if (preferences.circledVertices) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }

  glEnableClientState(GL_VERTEX_ARRAY);

  if (data != nullptr) {
    if (preferences.noVertices == false) {  // DRAW POINTS FIRST
      glColor3d(preferences.vertexColorR, preferences.vertexColorG,
                preferences.vertexColorB);
      glDrawArrays(GL_POINTS, 0, (*data).getPointArrayLength() / 3);
    }

    glColor3d(preferences.lineColorR, preferences.lineColorG,
              preferences.lineColorB);

    glVertexPointer(3, GL_DOUBLE, 0, (*data).getPointArray().get());
    glDrawElements(GL_LINES, (*data).getIndexArrayLength(), GL_UNSIGNED_INT,
                   (*data).getIndexArray().get());
  }

  glDisableClientState(GL_VERTEX_ARRAY);
}

}  // namespace s21
