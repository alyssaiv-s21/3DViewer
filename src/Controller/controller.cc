#include "controller.h"

void s21::ViewerController::open_file(const char *file_name) {
  model->open_file(file_name);
}

double *s21::ViewerController::get_vertex() { return model->get_vertex(); }

int *s21::ViewerController::get_facet() { return model->get_facet(); }

int s21::ViewerController::get_qty_vertex() { return model->get_qty_vertex(); }

int s21::ViewerController::get_qty_facet() { return model->get_qty_facet(); }

void s21::ViewerController::restore_vertex() { model->restore_vertex(); }

void s21::ViewerController::translating(int x_move, int y_move, int z_move) {
  model->translating(x_move, y_move, z_move);
}

void s21::ViewerController::scale_change(int scale) {
  model->scale_change(scale);
}

void s21::ViewerController::x_rotation(int x_spin) {
  model->x_rotation(x_spin);
}
void s21::ViewerController::y_rotation(int y_spin) {
  model->y_rotation(y_spin);
}

void s21::ViewerController::z_rotation(int z_spin) {
  model->z_rotation(z_spin);
}
