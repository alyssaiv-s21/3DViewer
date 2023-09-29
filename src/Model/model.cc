#include "model.h"

#include <cmath>
#include <fstream>

s21::ViewerModel::ViewerModel() : max_vertex_(0), vertex_in_file_(3, 0) {}

void s21::ViewerModel::open_file(const char *file_name) {
  std::fstream file_obj;
  std::string line;
  file_obj.open(file_name, std::ios::in);
  if (file_obj.is_open()) {
    clean_vectors();
    while (getline(file_obj, line)) {
      if (line[0] == 'v' && line[1] == ' ') {
        parsing_v_string(line);
      }
      if (line[0] == 'f') {
        parsing_f_string(line);
      }
    }
    vertex_normalize();
    vertex_changed_ = vertex_in_file_;
    file_obj.close();
  } else {
    throw "Unable to open file!";
  }
}

double *s21::ViewerModel::get_vertex() { return vertex_changed_.data(); }

int *s21::ViewerModel::get_facet() { return matrix_facet_.data(); }

int s21::ViewerModel::get_qty_vertex() { return vertex_in_file_.size() / 3; }

int s21::ViewerModel::get_qty_facet() { return matrix_facet_.size(); }

void s21::ViewerModel::restore_vertex() { vertex_changed_ = vertex_in_file_; }

void s21::ViewerModel::translating(int x_move, int y_move, int z_move) {
  if (x_move != 0) {
    for (size_t i = 0; i < vertex_changed_.size(); i += 3) {
      vertex_changed_[i] = vertex_changed_[i] + (double)x_move / 50;
    }
  }
  if (y_move != 0) {
    for (size_t i = 1; i < vertex_changed_.size(); i += 3) {
      vertex_changed_[i] = vertex_changed_[i] + (double)y_move / 50;
    }
  }
  if (z_move != 0) {
    for (size_t i = 2; i < vertex_changed_.size(); i += 3) {
      vertex_changed_[i] = vertex_changed_[i] + (double)z_move / 50;
    }
  }
}

void s21::ViewerModel::scale_change(int scale) {
  if (scale != 0) {
    if (scale < -100) {
      scale = -100;
    }
    double scale_in_fn = 1 + scale / 100.;
    for (size_t i = 0; i < vertex_changed_.size(); ++i) {
      vertex_changed_[i] = vertex_changed_[i] * scale_in_fn;
    }
  }
}

void s21::ViewerModel::x_rotation(int x_spin) {
  if (x_spin != 0) {
    s21::VecRotation rotation;
    s21::DegreeAdapter adapter(&rotation);
    adapter.x_rotation(vertex_changed_, x_spin);
  }
}

void s21::ViewerModel::y_rotation(int y_spin) {
  if (y_spin != 0) {
    s21::VecRotation rotation;
    s21::DegreeAdapter adapter(&rotation);
    adapter.y_rotation(vertex_changed_, y_spin);
  }
}

void s21::ViewerModel::z_rotation(int z_spin) {
  if (z_spin != 0) {
    s21::VecRotation rotation;
    s21::DegreeAdapter adapter(&rotation);
    adapter.z_rotation(vertex_changed_, z_spin);
  }
}

void s21::ViewerModel::vertex_normalize() {
  if (max_vertex_) {
    for (size_t i = 0; i < vertex_in_file_.size(); ++i) {
      vertex_in_file_[i] = vertex_in_file_[i] / max_vertex_;
    }
  }
}

void s21::ViewerModel::clean_vectors() {
  max_vertex_ = 0;
  vertex_in_file_.clear();
  vertex_in_file_ = {0, 0, 0};
  vertex_in_file_.shrink_to_fit();
  matrix_facet_.clear();
  matrix_facet_.shrink_to_fit();
}

void s21::ViewerModel::parsing_v_string(std::string &line) {
  char *sub_str = &line[2];
  char *endstr;
  int count = 0;
  for (; count < 3; ++count) {
    double num = strtod(sub_str, &endstr);
    if (fabs(num) > max_vertex_) {
      max_vertex_ = num;
    }
    vertex_in_file_.push_back(num);
    sub_str = endstr;
  }
}

void s21::ViewerModel::parsing_f_string(std::string &line) {
  int first_vertex = -1;
  for (size_t i = 0; i < line.size(); i++) {
    if (line[i] == ' ') {
      char *sub_str = &line[i + 1];
      int temp_vertex = (int)strtod(sub_str, nullptr);
      matrix_facet_.push_back(temp_vertex);
      if (first_vertex == -1) {
        first_vertex = temp_vertex;
      } else {
        matrix_facet_.push_back(temp_vertex);
      }
    }
  }
  matrix_facet_.push_back(first_vertex);
}
