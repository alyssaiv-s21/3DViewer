#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  my_glview_ = new qlview;
  v_settings_ = ui->openGLWidget->v_settings_;
  on_push_default_setting_clicked();
  set_ = new s21::SettingMemento(ui);
  set_->getMementoState();
}

MainWindow::MainWindow(s21::ViewerController *controller) : MainWindow() {
  controller_ = controller;
  ui->openGLWidget->set_controller(controller_);
}

MainWindow::~MainWindow() {
  set_->setMementoState();
  delete ui;
  delete my_glview_;
  delete set_;
}

//  Press on movement buttons and sliders (translating, rotation, scale)

void MainWindow::on_x_move_slider_sliderMoved(int position) {
  ui->x_move_box->setText(QString::number(position));
}
void MainWindow::on_x_move_box_textChanged(const QString &arg1) {
  int x_move = arg1.toInt();
  ui->x_move_slider->setValue(x_move);
  ui->openGLWidget->x_move_ = x_move;
  ui->openGLWidget->update();
}

void MainWindow::on_y_move_slider_sliderMoved(int position) {
  ui->y_move_box->setText(QString::number(position));
}
void MainWindow::on_y_move_box_textChanged(const QString &arg1) {
  int y_move = arg1.toInt();
  ui->y_move_slider->setValue(y_move);
  ui->openGLWidget->y_move_ = y_move;
  ui->openGLWidget->update();
}

void MainWindow::on_z_move_slider_sliderMoved(int position) {
  ui->z_move_box->setText(QString::number(position));
}
void MainWindow::on_z_move_box_textChanged(const QString &arg1) {
  int z_move = arg1.toInt();
  ui->z_move_slider->setValue(z_move);
  ui->openGLWidget->z_move_ = z_move;
  ui->openGLWidget->update();
}

void MainWindow::on_x_rotation_slider_sliderMoved(int position) {
  ui->x_rotation_box->setText(QString::number(position));
}
void MainWindow::on_x_rotation_box_textChanged() {
  int x_spin = ui->x_rotation_box->text().toInt();
  ui->x_rotation_slider->setValue(x_spin);
  ui->openGLWidget->x_spin_ = x_spin;
  ui->openGLWidget->update();
}

void MainWindow::on_y_rotation_slider_sliderMoved(int position) {
  ui->y_rotation_box->setText(QString::number(position));
}
void MainWindow::on_y_rotation_box_textChanged(const QString &arg1) {
  int y_spin = arg1.toInt();
  ui->y_rotation_slider->setValue(y_spin);
  ui->openGLWidget->y_spin_ = y_spin;
  ui->openGLWidget->update();
}

void MainWindow::on_z_rotation_slider_sliderMoved(int position) {
  ui->z_rotation_box->setText(QString::number(position));
}
void MainWindow::on_z_rotation_box_textChanged(const QString &arg1) {
  int z_spin = arg1.toInt();
  ui->z_rotation_slider->setValue(z_spin);
  ui->openGLWidget->z_spin_ = z_spin;
  ui->openGLWidget->update();
}

void MainWindow::on_scale_slider_sliderMoved(int position) {
  ui->scale_box->setText(QString::number(position));
}
void MainWindow::on_scale_box_textChanged(const QString &arg1) {
  int scale = arg1.toInt();
  ui->scale_slider->setValue(scale);
  ui->openGLWidget->scale_ = scale;
  ui->openGLWidget->update();
}

//  Press on setting buttons (appearance of edges, vertixes, background and
//  projection)

void MainWindow::on_dashed_button_clicked() {
  v_settings_->set_facet_dased(1);
  ui->openGLWidget->update();
}
void MainWindow::on_solid_button_clicked() {
  v_settings_->set_facet_dased(0);
  ui->openGLWidget->update();
}

void MainWindow::on_color_edge_combo_textActivated(const QString &arg1) {
  v_settings_->set_facet_color(arg1.toStdString());
  ui->openGLWidget->update();
}

void MainWindow::on_thickness_edge_slider_sliderMoved(int position) {
  v_settings_->set_facet_thickness(position);
  ui->openGLWidget->update();
}

void MainWindow::on_non_button_clicked() {
  v_settings_->set_vertex_shape(0);
  v_settings_->set_vertex_size(0);
  ui->size_vertices_slider->setSliderPosition(1);
  emit ui->size_vertices_slider->sliderMoved(1);
  ui->openGLWidget->update();
}
void MainWindow::on_circle_button_clicked() {
  v_settings_->set_vertex_shape(1);
  ui->openGLWidget->update();
}
void MainWindow::on_square_button_clicked() {
  v_settings_->set_vertex_shape(2);
  ui->openGLWidget->update();
}

void MainWindow::on_color_vertices_combo_textActivated(const QString &arg1) {
  v_settings_->set_vertex_color(arg1.toStdString());
  ui->openGLWidget->update();
}

void MainWindow::on_size_vertices_slider_sliderMoved(int position) {
  v_settings_->set_vertex_size(position);
  ui->openGLWidget->update();
}

void MainWindow::on_background_combo_textActivated(const QString &arg1) {
  v_settings_->set_bg_color(arg1.toStdString());
  ui->openGLWidget->update();
}

void MainWindow::on_parallel_button_clicked() {
  v_settings_->set_projection(0);
  ui->openGLWidget->update();
}
void MainWindow::on_central_button_clicked() {
  v_settings_->set_projection(1);
  ui->openGLWidget->update();
}

//  Press on Open file button

void MainWindow::on_open_file_clicked() {
  const QString current_dir = QDir::currentPath();
  QString full_file_name;
  full_file_name = QFileDialog::getOpenFileName(this, tr("Open OBJ file"),
                                                current_dir, tr("*.obj"));
  if (full_file_name.isNull()) {
    ui->file_name->setText("Please open another file");
  } else {
    ui->file_name->setText(full_file_name);

    ui->openGLWidget->file_name_ = nullptr;
    QByteArray ba = full_file_name.toLocal8Bit();
    ui->openGLWidget->file_name_ = ba.data();

    try {
      ui->openGLWidget->open_new_file();
    } catch (...) {
      ui->file_name->setText(
          "This file can't be read, please open another file");
    }

    ui->openGLWidget->update();

    int qty_vertexes = controller_->get_qty_vertex() - 1;
    ui->qty_vertice->setText(QString::number(qty_vertexes, 'f', 0));

    int qty_facets = controller_->get_qty_facet() / 4;
    ui->qty_facet->setText(QString::number(qty_facets, 'f', 0));
  }
}

void MainWindow::on_save_jpeg_clicked() {
  QString screenshot_dir;
  screenshot_dir = QFileDialog::getSaveFileName(this, tr("Save screenshot"), "",
                                                tr("jpg (*.jpg);;bmp (*.bmp)"));
  ui->openGLWidget->grab().save(screenshot_dir);
}

void MainWindow::on_save_gif_clicked() {
  gif_facade_ = new s21::GifFacade(this, ui);
  gif_facade_->make_gif();
}

void MainWindow::on_push_default_setting_clicked() {
  ui->x_move_box->setText("0");
  ui->x_move_slider->setRange(-100, 100);
  ui->y_move_box->setText("0");
  ui->y_move_slider->setRange(-100, 100);
  ui->z_move_box->setText("0");
  ui->z_move_slider->setRange(-100, 100);
  ui->x_rotation_box->setText("0");
  ui->x_rotation_slider->setRange(0, 360);
  ui->y_rotation_box->setText("0");
  ui->y_rotation_slider->setRange(0, 360);
  ui->z_rotation_box->setText("0");
  ui->z_rotation_slider->setRange(0, 360);
  ui->scale_box->setText("0");
  ui->scale_slider->setRange(-100, 300);
  ui->thickness_edge_slider->setRange(1, 30);
  ui->size_vertices_slider->setRange(1, 30);
  ui->x_move_slider->setValue(0);
  ui->openGLWidget->x_move_ = 0;
  ui->y_move_slider->setValue(0);
  ui->openGLWidget->y_move_ = 0;
  ui->z_move_slider->setValue(0);
  ui->openGLWidget->z_move_ = 0;
  ui->x_rotation_slider->setValue(0);
  ui->openGLWidget->x_spin_ = 0;
  ui->y_rotation_slider->setValue(0);
  ui->openGLWidget->y_spin_ = 0;
  ui->z_rotation_slider->setValue(0);
  ui->openGLWidget->z_spin_ = 0;
  ui->openGLWidget->scale_ = 0;
  ui->solid_button->click();
  ui->non_button->click();
  ui->parallel_button->click();
  ui->thickness_edge_slider->setValue(0);
  v_settings_->set_facet_thickness(1);
  ui->size_vertices_slider->setValue(0);
  v_settings_->set_vertex_size(1);
  v_settings_->set_facet_color(1);
  ui->color_edge_combo->setCurrentIndex(0);
  v_settings_->set_vertex_color(1);
  ui->color_vertices_combo->setCurrentIndex(0);
  v_settings_->set_bg_color(0);
  ui->background_combo->setCurrentIndex(0);
  ui->openGLWidget->update();
}
