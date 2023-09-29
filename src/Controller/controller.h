#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H

#include "../Model/model.h"

namespace s21 {

class ViewerController {
 public:
  explicit ViewerController(ViewerModel *m) : model(m) {}
  ~ViewerController() {}
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
  ViewerModel *model;
};
}  // namespace s21

#endif  // #ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H
