#ifndef QLVIEW_H
#define QLVIEW_H

#define GL_SILENCE_DEPRECATION
#include <QMessageBox>
#include <QOpenGLWidget>
#include <QWheelEvent>

#include "Controller/controller.h"
#include "settings.h"

/// @brief GLWidget class
class qlview : public QOpenGLWidget {
 public:
  qlview(QWidget *parent = nullptr);
  ~qlview();

  void initializeGL() override;
  void paintGL() override;

  QPoint firstPos;
  void mousePressEvent(QMouseEvent *press_event) override;
  void mouseMoveEvent(QMouseEvent *move_event) override;
  void wheelEvent(QWheelEvent *wheel) override;

  void open_new_file();
  void set_controller(s21::ViewerController *c);

  const char *file_name_ = nullptr;
  int x_move_ = 0;
  int y_move_ = 0;
  int z_move_ = 0;
  int x_spin_ = 0;
  int y_spin_ = 0;
  int z_spin_ = 0;
  int scale_ = 0;
  s21::VisualSettigns *v_settings_;

 private:
  void change_vertex_appearance();
  void change_facet_appearance();
  void change_background();
  s21::ViewerController *controller_ = nullptr;
};

#endif  // QLVIEW_H
