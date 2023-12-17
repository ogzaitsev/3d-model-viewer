#ifndef CPP4_3DVIEWER_V2_3DVIEWER_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_3DVIEWER_CONTROLLER_CONTROLLER_H_

#include <QMainWindow>
#include <QTimer>

#include "../model/Facade.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Controller;
}
QT_END_NAMESPACE

class Controller : public QMainWindow {
  Q_OBJECT

 public:
  Controller(QWidget *parent = nullptr);
  void readSettings();
  void writeSettings();
  void setPreferences();
  ~Controller();

 private slots:
  void on_pushButton_file_select_clicked();

  void on_slider_rotateX_sliderMoved(int position);

  void on_slider_rotateY_sliderMoved(int position);

  void on_slider_rotateZ_sliderMoved(int position);

  void on_spinBox_scale_valueChanged(double ratio);

  void on_spinBox_x_valueChanged(double value);

  void on_spinBox_y_valueChanged(double value);

  void on_spinBox_z_valueChanged(double value);

  void on_horizontalSlider_vertexSize_2_valueChanged(int value);

  void on_horizontalSlider_line_width_2_valueChanged(int value);

  void on_radioButton_no_2_clicked();

  void on_radioButton_circle_2_clicked();

  void on_radioButton_square_2_clicked();

  void on_radioButton_solid_line_2_clicked();

  void on_radioButton_dotted_line_2_clicked();

  void on_radioButton_parr_2_clicked();

  void on_radioButton_center_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

 private:
  Ui::Controller *ui;
  bool fileSelected;
  ogzaitsev::Facade *facade;

  void resetView();
};
#endif  // CPP4_3DVIEWER_V2_3DVIEWER_CONTROLLER_CONTROLLER_H_
