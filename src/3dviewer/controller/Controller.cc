#include "Controller.h"

#include <QColorDialog>
#include <QFileDialog>

#include "../model/DataBuilder.h"
#include "ui_view.h"

Controller::Controller(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Controller), fileSelected(false) {
  ui->setupUi(this);
  facade = new ogzaitsev::Facade(ui->SceneWidget);
}

Controller::~Controller() {
  delete facade;
  delete ui;
}

void Controller::on_pushButton_file_select_clicked() {
  QString filename = QFileDialog::getOpenFileName(
      this, "choose file", QDir::currentPath(), ".obj file(*.obj)");
  if (filename.isEmpty()) {
    ui->statusbar->showMessage("Wrong filename");
    return;
  }
  std::string filenameStd = filename.toStdString();
  ui->statusbar->showMessage(
      QString::fromStdString(facade->openFileAndDraw(filenameStd)));
  fileSelected = true;
  resetView();
}

void Controller::resetView() {
  ui->spinBox_scale->setValue(1.0);
  ui->spinBox_x->setValue(0);
  ui->spinBox_y->setValue(0);
  ui->spinBox_z->setValue(0);
  ui->slider_rotateX->setValue(0);
  ui->slider_rotateY->setValue(0);
  ui->slider_rotateZ->setValue(0);
}

void Controller::on_slider_rotateX_sliderMoved(int angle) {
  if (fileSelected) facade->rotateObject(static_cast<double>(angle), 'x');
}

void Controller::on_slider_rotateY_sliderMoved(int angle) {
  if (fileSelected) facade->rotateObject(static_cast<double>(angle), 'y');
}

void Controller::on_slider_rotateZ_sliderMoved(int angle) {
  if (fileSelected) facade->rotateObject(static_cast<double>(angle), 'z');
}

void Controller::on_spinBox_scale_valueChanged(double ratio) {
  if (ratio == 0) return;
  if (fileSelected) facade->scaleObject(ratio);
}

void Controller::on_spinBox_x_valueChanged(double value) {
  if (fileSelected) facade->moveObject(value, 'x');
}

void Controller::on_spinBox_y_valueChanged(double value) {
  if (fileSelected) facade->moveObject(value, 'y');
}

void Controller::on_spinBox_z_valueChanged(double value) {
  if (fileSelected) facade->moveObject(value, 'z');
}

void Controller::setPreferences() {
  if (ui->SceneWidget->preferences.parallel) {
    ui->radioButton_parr_2->setChecked(true);
  } else {
    ui->radioButton_center_2->setChecked(true);
  }

  if (ui->SceneWidget->preferences.solidLine) {
    ui->radioButton_solid_line_2->setChecked(true);
  } else if (ui->SceneWidget->preferences.dashedLine) {
    ui->radioButton_dotted_line_2->setChecked(true);
  }

  if (ui->SceneWidget->preferences.noVertices) {
    ui->radioButton_no_2->setChecked(true);
  } else if (ui->SceneWidget->preferences.circledVertices) {
    ui->radioButton_circle_2->setChecked(true);
  } else {
    ui->radioButton_square_2->setChecked(true);
  }

  ui->horizontalSlider_line_width_2->setValue(
      ui->SceneWidget->preferences.lineWidth);
  ui->horizontalSlider_vertexSize_2->setValue(
      ui->SceneWidget->preferences.vertexSize);
}

void Controller::on_horizontalSlider_vertexSize_2_valueChanged(int value) {
  ui->SceneWidget->preferences.vertexSize = value;
  ui->SceneWidget->update();
}

void Controller::on_horizontalSlider_line_width_2_valueChanged(int value) {
  ui->SceneWidget->preferences.lineWidth = value;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_no_2_clicked() {
  ui->SceneWidget->preferences.noVertices = true;
  ui->SceneWidget->preferences.squaredVertices = false;
  ui->SceneWidget->preferences.circledVertices = false;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_circle_2_clicked() {
  ui->SceneWidget->preferences.noVertices = false;
  ui->SceneWidget->preferences.squaredVertices = false;
  ui->SceneWidget->preferences.circledVertices = true;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_square_2_clicked() {
  ui->SceneWidget->preferences.noVertices = false;
  ui->SceneWidget->preferences.squaredVertices = true;
  ui->SceneWidget->preferences.circledVertices = false;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_solid_line_2_clicked() {
  ui->SceneWidget->preferences.solidLine = true;
  ui->SceneWidget->preferences.dashedLine = false;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_dotted_line_2_clicked() {
  ui->SceneWidget->preferences.solidLine = false;
  ui->SceneWidget->preferences.dashedLine = true;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_parr_2_clicked() {
  ui->SceneWidget->preferences.parallel = true;
  ui->SceneWidget->preferences.central = false;
  ui->SceneWidget->update();
}

void Controller::on_radioButton_center_2_clicked() {
  ui->SceneWidget->preferences.parallel = false;
  ui->SceneWidget->preferences.central = true;
  ui->SceneWidget->update();
}

void Controller::on_pushButton_clicked() {  // background color
  QColor color = QColorDialog::getColor(Qt::gray, this, "Background color");
  if (color.isValid()) {
    ui->SceneWidget->preferences.backColorR = color.redF();
    ui->SceneWidget->preferences.backColorG = color.greenF();
    ui->SceneWidget->preferences.backColorB = color.blueF();
    ui->SceneWidget->update();
  }
}

void Controller::on_pushButton_2_clicked() {  // vertex color
  QColor color = QColorDialog::getColor(Qt::red, this, "Vertices color");
  if (color.isValid()) {
    ui->SceneWidget->preferences.vertexColorR = color.redF();
    ui->SceneWidget->preferences.vertexColorG = color.greenF();
    ui->SceneWidget->preferences.vertexColorB = color.blueF();
    ui->SceneWidget->update();
  }
}

void Controller::on_pushButton_3_clicked() {
  QColor color = QColorDialog::getColor(Qt::blue, this, "Lines color");
  if (color.isValid()) {
    ui->SceneWidget->preferences.lineColorR = color.redF();
    ui->SceneWidget->preferences.lineColorG = color.greenF();
    ui->SceneWidget->preferences.lineColorB = color.blueF();
    ui->SceneWidget->update();
  }
}

