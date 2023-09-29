#include "settings.h"

void s21::VisualSettigns::set_facet_dased(int push) { is_facet_dashed_ = push; }

void s21::VisualSettigns::set_facet_color(std::string color) {
  facet_color_ = map_color[color];
}

void s21::VisualSettigns::set_facet_color(int color) { facet_color_ = color; }

void s21::VisualSettigns::set_facet_thickness(double size) {
  facet_thickness_ = size;
}

void s21::VisualSettigns::set_vertex_shape(int shape) { vertex_shape_ = shape; }

void s21::VisualSettigns::set_vertex_color(std::string color) {
  vertex_color_ = map_color[color];
}

void s21::VisualSettigns::set_vertex_color(int color) { vertex_color_ = color; }

void s21::VisualSettigns::set_vertex_size(int size) { vertex_size_ = size; }

void s21::VisualSettigns::set_bg_color(std::string color) {
  bg_color_ = map_color[color];
}

void s21::VisualSettigns::set_bg_color(int color) { bg_color_ = color; }

void s21::VisualSettigns::set_projection(int type) { projection_type_ = type; }

int s21::VisualSettigns::get_facet_dased() { return is_facet_dashed_; }

int s21::VisualSettigns::get_facet_color() { return facet_color_; }

double s21::VisualSettigns::get_facet_thickness() { return facet_thickness_; }

int s21::VisualSettigns::get_vertex_shape() { return vertex_shape_; }

int s21::VisualSettigns::get_vertex_color() { return vertex_color_; }

int s21::VisualSettigns::get_vertex_size() { return vertex_size_; }

int s21::VisualSettigns::get_bg_color() { return bg_color_; }

int s21::VisualSettigns::get_projection() { return projection_type_; }
