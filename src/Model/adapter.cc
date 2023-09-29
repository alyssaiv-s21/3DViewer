#include "adapter.h"

#include <cmath>

void s21::VecRotation::x_rotation(std::vector<double> &vertex,
                                  double x_spin_radian) {
  if (x_spin_radian != 0) {
    for (unsigned int i = 0; i < vertex.size(); i += 3) {
      double y = vertex[i + 1];
      double z = vertex[i + 2];
      vertex[i + 1] = cos(x_spin_radian) * y - sin(x_spin_radian) * z;
      vertex[i + 2] = sin(x_spin_radian) * y + cos(x_spin_radian) * z;
    }
  }
}
void s21::VecRotation::y_rotation(std::vector<double> &vertex,
                                  double y_spin_radian) {
  if (y_spin_radian != 0) {
    for (unsigned int i = 0; i < vertex.size(); i += 3) {
      double x = vertex[i];
      double z = vertex[i + 2];
      vertex[i] = cos(y_spin_radian) * x - sin(y_spin_radian) * z;
      vertex[i + 2] = sin(y_spin_radian) * x + cos(y_spin_radian) * z;
    }
  }
}
void s21::VecRotation::z_rotation(std::vector<double> &vertex,
                                  double z_spin_radian) {
  if (z_spin_radian != 0) {
    for (unsigned int i = 0; i < vertex.size(); i += 3) {
      double x = vertex[i];
      double y = vertex[i + 1];
      vertex[i] = cos(z_spin_radian) * x - sin(z_spin_radian) * y;
      vertex[i + 1] = sin(z_spin_radian) * x + cos(z_spin_radian) * y;
    }
  }
}

s21::DegreeAdapter::DegreeAdapter(VecRotation *adaptee) : adaptee_(adaptee) {}
void s21::DegreeAdapter::x_rotation(std::vector<double> &vertex,
                                    int x_spin_degree) {
  double x_spin_radian = x_spin_degree * (M_PI / 180);
  adaptee_->x_rotation(vertex, x_spin_radian);
}
void s21::DegreeAdapter::y_rotation(std::vector<double> &vertex,
                                    int y_spin_degree) {
  double y_spin_radian = y_spin_degree * (M_PI / 180);
  adaptee_->y_rotation(vertex, y_spin_radian);
}
void s21::DegreeAdapter::z_rotation(std::vector<double> &vertex,
                                    int z_spin_degree) {
  double z_spin_radian = z_spin_degree * (M_PI / 180);
  adaptee_->z_rotation(vertex, z_spin_radian);
}
