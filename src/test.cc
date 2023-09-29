#include <string>

#include "Controller/controller.h"
#include "Model/adapter.h"
#include "Model/model.h"
#include "gtest/gtest.h"

using namespace s21;

TEST(ViewerTest, case1) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  int a = controller.get_qty_vertex();
  int b = controller.get_qty_facet();
  EXPECT_EQ(a, 3);
  EXPECT_EQ(b, 8);
  double *vertex = controller.get_vertex();
  EXPECT_EQ(vertex[0], 0);
  EXPECT_EQ(vertex[1], 0);
  EXPECT_EQ(vertex[2], 0);
  EXPECT_EQ(vertex[3], 1);
  EXPECT_EQ(vertex[4], 0);
  EXPECT_EQ(vertex[5], 0.25);
  EXPECT_EQ(vertex[6], 0.5);
  EXPECT_EQ(vertex[7], 0.5);
  EXPECT_EQ(vertex[8], 1);
  int *facet = controller.get_facet();
  EXPECT_EQ(facet[0], 1);
  EXPECT_EQ(facet[1], 2);
  EXPECT_EQ(facet[2], 2);
  EXPECT_EQ(facet[3], 1);
  EXPECT_EQ(facet[4], 2);
  EXPECT_EQ(facet[5], 1);
  EXPECT_EQ(facet[6], 1);
  EXPECT_EQ(facet[7], 2);
}

TEST(ViewerTest, case2) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/tt.obj";
  const char *file_name = name.c_str();
  EXPECT_ANY_THROW(controller.open_file(file_name));
}

TEST(ViewerTest, case3) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.scale_change(100);
  double *vertex = controller.get_vertex();
  EXPECT_EQ(vertex[0], 0);
  EXPECT_EQ(vertex[1], 0);
  EXPECT_EQ(vertex[2], 0);
  EXPECT_EQ(vertex[3], 2);
  EXPECT_EQ(vertex[4], 0);
  EXPECT_EQ(vertex[5], 0.5);
  EXPECT_EQ(vertex[6], 1);
  EXPECT_EQ(vertex[7], 1);
  EXPECT_EQ(vertex[8], 2);
}

TEST(ViewerTest, case4) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.translating(50, 100, 150);
  double *vertex = controller.get_vertex();
  EXPECT_EQ(vertex[0], 1);
  EXPECT_EQ(vertex[1], 2);
  EXPECT_EQ(vertex[2], 3);
  EXPECT_EQ(vertex[3], 2);
  EXPECT_EQ(vertex[4], 2);
  EXPECT_EQ(vertex[5], 3.25);
  EXPECT_EQ(vertex[6], 1.5);
  EXPECT_EQ(vertex[7], 2.5);
  EXPECT_EQ(vertex[8], 4);
}

TEST(ViewerTest, case5) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.x_rotation(90);
  double *vertex = controller.get_vertex();
  EXPECT_NEAR(vertex[0], 0, 1e-7);
  EXPECT_NEAR(vertex[1], 0, 1e-7);
  EXPECT_NEAR(vertex[2], 0, 1e-7);
  EXPECT_NEAR(vertex[3], 1, 1e-7);
  EXPECT_NEAR(vertex[4], -0.25, 1e-7);
  EXPECT_NEAR(vertex[5], 0, 1e-7);
  EXPECT_NEAR(vertex[6], 0.5, 1e-7);
  EXPECT_NEAR(vertex[7], -1, 1e-7);
  EXPECT_NEAR(vertex[8], 0.5, 1e-7);
}

TEST(ViewerTest, case6) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.y_rotation(90);
  double *vertex = controller.get_vertex();
  EXPECT_NEAR(vertex[0], 0, 1e-7);
  EXPECT_NEAR(vertex[1], 0, 1e-7);
  EXPECT_NEAR(vertex[2], 0, 1e-7);
  EXPECT_NEAR(vertex[3], -0.25, 1e-7);
  EXPECT_NEAR(vertex[4], 0, 1e-7);
  EXPECT_NEAR(vertex[5], 1, 1e-7);
  EXPECT_NEAR(vertex[6], -1, 1e-7);
  EXPECT_NEAR(vertex[7], 0.5, 1e-7);
  EXPECT_NEAR(vertex[8], 0.5, 1e-7);
}

TEST(ViewerTest, case7) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.z_rotation(90);
  double *vertex = controller.get_vertex();
  EXPECT_NEAR(vertex[0], 0, 1e-7);
  EXPECT_NEAR(vertex[1], 0, 1e-7);
  EXPECT_NEAR(vertex[2], 0, 1e-7);
  EXPECT_NEAR(vertex[3], 0, 1e-7);
  EXPECT_NEAR(vertex[4], 1, 1e-7);
  EXPECT_NEAR(vertex[5], 0.25, 1e-7);
  EXPECT_NEAR(vertex[6], -0.5, 1e-7);
  EXPECT_NEAR(vertex[7], 0.5, 1e-7);
  EXPECT_NEAR(vertex[8], 1, 1e-7);
}

TEST(ViewerTest, case8) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.scale_change(-500);
  double *vertex = controller.get_vertex();
  EXPECT_NEAR(vertex[0], 0, 1e-7);
  EXPECT_NEAR(vertex[1], 0, 1e-7);
  EXPECT_NEAR(vertex[2], 0, 1e-7);
  EXPECT_NEAR(vertex[3], 0, 1e-7);
  EXPECT_NEAR(vertex[4], 0, 1e-7);
  EXPECT_NEAR(vertex[5], 0, 1e-7);
  EXPECT_NEAR(vertex[6], 0, 1e-7);
  EXPECT_NEAR(vertex[7], 0, 1e-7);
  EXPECT_NEAR(vertex[8], 0, 1e-7);
}

TEST(ViewerTest, case9) {
  ViewerModel model;
  ViewerController controller(&model);
  std::string name = "../data-samples/obj_files/test.obj";
  const char *file_name = name.c_str();
  controller.open_file(file_name);
  controller.restore_vertex();
  double *vertex = controller.get_vertex();
  EXPECT_EQ(vertex[0], 0);
  EXPECT_EQ(vertex[1], 0);
  EXPECT_EQ(vertex[2], 0);
  EXPECT_EQ(vertex[3], 1);
  EXPECT_EQ(vertex[4], 0);
  EXPECT_EQ(vertex[5], 0.25);
  EXPECT_EQ(vertex[6], 0.5);
  EXPECT_EQ(vertex[7], 0.5);
  EXPECT_EQ(vertex[8], 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
