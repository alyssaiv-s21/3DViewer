#ifndef CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H
#define CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H

#include <map>
#include <string>

namespace s21 {

/// @brief Class stores the visual settings of the 3D Object, has setter and getter for each attribute
class VisualSettigns {
 public:
  void set_facet_dased(int push);
  void set_facet_color(std::string color);
  void set_facet_color(int color);
  void set_facet_thickness(double size);
  void set_vertex_shape(int shape);
  void set_vertex_color(std::string color);
  void set_vertex_color(int color);
  void set_vertex_size(int size);
  void set_bg_color(std::string color);
  void set_bg_color(int color);
  void set_projection(int type);

  int get_facet_dased();
  int get_facet_color();
  double get_facet_thickness();
  int get_vertex_shape();
  int get_vertex_color();
  int get_vertex_size();
  int get_bg_color();
  int get_projection();

 private:
  std::map<std::string, int> map_color = {{"black", 0},  {"white", 1},
                                          {"purple", 2}, {"pink", 3},
                                          {"blue", 4},   {"green", 5}};
  int is_facet_dashed_ = 0;
  int facet_color_ = 1;
  double facet_thickness_ = 1;
  int vertex_shape_ = 0;
  int vertex_color_ = 1;
  int vertex_size_ = 0;
  int bg_color_ = 0;
  int projection_type_ = 0;
};
}  // namespace s21
#endif  // #ifndef CPP4_3DVIEWER_V2_0_VIEW_SETTINGS_H
