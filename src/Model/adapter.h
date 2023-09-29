#ifndef CPP4_3DVIEWER_V2_0_MODEL_ADAPTER_H
#define CPP4_3DVIEWER_V2_0_MODEL_ADAPTER_H

#include <vector>

namespace s21 {
/// @brief Class for vector rotation change, work with radian 
class VecRotation {
 public:
  VecRotation() {}
  ~VecRotation() {}
  void x_rotation(std::vector<double> &vertex, double x_spin_radian);
  void y_rotation(std::vector<double> &vertex, double y_spin_radian);
  void z_rotation(std::vector<double> &vertex, double z_spin_radian);
};

/// @brief Adapter - converts degrees (from Model) to radians (in Rotation class)
class DegreeAdapter {
 public:
  explicit DegreeAdapter(VecRotation *adaptee);
  ~DegreeAdapter() {}
  void x_rotation(std::vector<double> &vertex, int x_spin_degree);
  void y_rotation(std::vector<double> &vertex, int y_spin_degree);
  void z_rotation(std::vector<double> &vertex, int z_spin_degree);

 private:
  VecRotation *adaptee_;
};
}  // namespace s21
#endif  // #ifndef CPP4_3DVIEWER_V2_0_MODEL_ADAPTER_H
