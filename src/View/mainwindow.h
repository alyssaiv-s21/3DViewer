#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QSettings>
#include <QTimer>

#include "facade.h"
#include "memento.h"
#include "qlview.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class SettingMemento;
}

/// @brief MainWindow class - has all buttons and slots
class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  explicit MainWindow(s21::ViewerController *controller);
  ~MainWindow();

 private slots:
  void on_x_move_slider_sliderMoved(int position);
  void on_x_move_box_textChanged(const QString &arg1);
  void on_y_move_slider_sliderMoved(int position);
  void on_y_move_box_textChanged(const QString &arg1);
  void on_z_move_slider_sliderMoved(int position);
  void on_z_move_box_textChanged(const QString &arg1);
  void on_x_rotation_slider_sliderMoved(int position);
  void on_x_rotation_box_textChanged();
  void on_y_rotation_slider_sliderMoved(int position);
  void on_y_rotation_box_textChanged(const QString &arg1);
  void on_z_rotation_slider_sliderMoved(int position);
  void on_z_rotation_box_textChanged(const QString &arg1);
  void on_scale_box_textChanged(const QString &arg1);
  void on_scale_slider_sliderMoved(int position);
  void on_dashed_button_clicked();
  void on_solid_button_clicked();
  void on_thickness_edge_slider_sliderMoved(int position);
  void on_background_combo_textActivated(const QString &arg1);
  void on_color_edge_combo_textActivated(const QString &arg1);
  void on_size_vertices_slider_sliderMoved(int position);
  void on_color_vertices_combo_textActivated(const QString &arg1);
  void on_circle_button_clicked();
  void on_square_button_clicked();
  void on_non_button_clicked();
  void on_parallel_button_clicked();
  void on_central_button_clicked();
  void on_open_file_clicked();
  void on_push_default_setting_clicked();
  void on_save_jpeg_clicked();
  void on_save_gif_clicked();

 private:
  Ui::MainWindow *ui;
  qlview *my_glview_;
  s21::ViewerController *controller_;
  s21::SettingMemento *set_;
  s21::GifFacade *gif_facade_;
  s21::VisualSettigns *v_settings_;
};

#endif  // MAINWINDOW_H
