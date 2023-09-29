#ifndef CPP4_3DVIEWER_V2_0_MODEL_MODEL_H
#define CPP4_3DVIEWER_V2_0_MODEL_MODEL_H

#include <string>
#include <vector>

#include "adapter.h"

namespace s21 {

/// @brief Main class for parsing obj files
class ViewerModel {
 public:
  ViewerModel();
  ~ViewerModel() {}
  void open_file(const char *file_name);
  double *get_vertex();
  int *get_facet();
  int get_qty_vertex();
  int get_qty_facet();
  void restore_vertex();
  void translating(int x_move, int y_move, int z_move);
  void scale_change(int scale);
  void x_rotation(int x_spin);
  void y_rotation(int y_spin);
  void z_rotation(int z_spin);

 private:
  double max_vertex_;
  std::vector<double> vertex_in_file_;
  std::vector<double> vertex_changed_;
  std::vector<int> matrix_facet_;
  void vertex_normalize();
  void clean_vectors();
  void parsing_v_string(std::string &line);
  void parsing_f_string(std::string &line);
};
}  // namespace s21
#endif  // #ifndef CPP4_3DVIEWER_V2_0_MODEL_MODEL_H
