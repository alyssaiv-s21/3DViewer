#include "qlview.h"

#include <QDebug>
#include <iostream>

qlview::qlview(QWidget *parent) : QOpenGLWidget(parent) {
  v_settings_ = new s21::VisualSettigns;
}

qlview::~qlview() { delete v_settings_; }

void qlview::set_controller(s21::ViewerController *c) { controller_ = c; }

void qlview::open_new_file() {
  try {
    controller_->open_file(file_name_);
  } catch (...) {
    std::cout << "cant open file" << std::endl;
  }
}

void qlview::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glViewport(0, 0, 1800, 1800);
}

void qlview::paintGL() {
  controller_->restore_vertex();
  controller_->translating(x_move_, y_move_, z_move_);
  controller_->scale_change(scale_);
  controller_->x_rotation(x_spin_);
  controller_->y_rotation(y_spin_);
  controller_->z_rotation(z_spin_);

  change_vertex_appearance();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  change_background();

  glEnableClientState(GL_VERTEX_ARRAY);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glVertexPointer(3, GL_DOUBLE, 0, controller_->get_vertex());
  glDrawArrays(GL_POINTS, 0, controller_->get_qty_vertex());

  change_facet_appearance();
  glDrawElements(GL_LINES, controller_->get_qty_facet(), GL_UNSIGNED_INT,
                 controller_->get_facet());
  glDisableClientState(GL_VERTEX_ARRAY);
}

void qlview::mousePressEvent(QMouseEvent *press_event) {
  firstPos = press_event->pos();
}

void qlview::mouseMoveEvent(QMouseEvent *move_event) {
  if (move_event->buttons() & Qt::LeftButton) {
    int xMoveMouse = (firstPos.x() - move_event->pos().x());
    int yMoveMouse = (firstPos.y() - move_event->pos().y());
    x_move_ = -xMoveMouse / 4.5;
    y_move_ = yMoveMouse / 4.5;
    update();
  }
  if (move_event->buttons() & Qt::RightButton) {
    int yRotationMouse = (firstPos.x() - move_event->pos().x());
    int xRotationMouse = (firstPos.y() - move_event->pos().y());
    x_spin_ = xRotationMouse / 2.5;
    y_spin_ = -yRotationMouse / 2.5;
    update();
  }
}

void qlview::wheelEvent(QWheelEvent *wheel) {
  if (wheel->angleDelta().y() > 0) {
    scale_ = (scale_ + 10);
  } else {
    scale_ = (scale_ - 10);
  }
  update();
}

void qlview::change_vertex_appearance() {
  switch (v_settings_->get_vertex_color()) {
    case 0:  // black
      glColor3f(0.0, 0.0, 0.0);
      break;
    case 1:  // white
      glColor3f(1.0, 1.0, 1.0);
      break;
    case 2:  // purple
      glColor3f(0.8, 0.6, 1.0);
      break;
    case 3:  // pink
      glColor3f(1.0, 0.86, 0.898);
      break;
    case 4:  // blue
      glColor3f(0.0, 0.298, 0.6);
      break;
    case 5:  // green
      glColor3f(0.0, 0.4, 0.4);
      break;
  }
  if (v_settings_->get_vertex_shape() != 0) {
    glPointSize(v_settings_->get_vertex_size());
  } else {
    glPointSize(1);
  }
  if (v_settings_->get_vertex_shape() == 1) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }
}

void qlview::change_facet_appearance() {
  if (v_settings_->get_facet_dased()) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glLineWidth(v_settings_->get_facet_thickness());
  switch (v_settings_->get_facet_color()) {
    case 0:  // black
      glColor3f(0.0, 0.0, 0.0);
      break;
    case 1:  // white
      glColor3f(1.0, 1.0, 1.0);
      break;
    case 2:  // purple
      glColor3f(0.8, 0.6, 1.0);
      break;
    case 3:  // pink
      glColor3f(1.0, 0.86, 0.898);
      break;
    case 4:  // blue
      glColor3f(0.0, 0.298, 0.6);
      break;
    case 5:  // green
      glColor3f(0.0, 0.4, 0.4);
      break;
  }
}

void qlview::change_background() {
  if (v_settings_->get_projection() == 1) {
    glFrustum(-1.0, 1.0, -1.0, 1.0, 0.5, 10.0);
    controller_->translating(0, 0, -100);
  } else if (v_settings_->get_projection() == 0) {
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  }
  switch (v_settings_->get_bg_color()) {
    case 0:  // black bg
      glClearColor(0.0, 0.0, 0.0, 1.0);
      break;
    case 1:  // white bg
      glClearColor(1.0, 1.0, 1.0, 1.0);
      break;
    case 2:  // purple bg
      glClearColor(0.153, 0.051, 0.255, 1.0);
      break;
    case 3:  // pink bg
      glClearColor(1.0, 0.86, 0.898, 1.0);
      break;
    case 4:  // blue bg
      glClearColor(0.0, 0.298, 0.6, 1.0);
      break;
    case 5:  // green bg
      glClearColor(0.0, 0.4, 0.4, 1.0);
      break;
  }
}
