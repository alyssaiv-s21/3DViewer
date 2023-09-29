#include "mainwindow.h"
#include "ui_mainwindow.h"

s21::SettingMemento::SettingMemento(Ui::MainWindow *ui)
    : settings_(new QSettings("21school", "3DViewer", nullptr)), ui_(ui) {}

void s21::SettingMemento::getMementoState() {
  if (settings_ != nullptr) {
    ui_->openGLWidget->v_settings_->set_facet_dased(
        settings_->value("edges_type").toInt());
    ui_->openGLWidget->v_settings_->set_facet_color(
        settings_->value("edges_color").toInt());
    ui_->openGLWidget->v_settings_->set_facet_thickness(
        settings_->value("edges_thickness").toDouble());
    ui_->openGLWidget->v_settings_->set_vertex_shape(
        settings_->value("vertix_display_method").toInt());
    ui_->openGLWidget->v_settings_->set_vertex_color(
        settings_->value("vertex_color").toInt());
    ui_->openGLWidget->v_settings_->set_vertex_size(
        settings_->value("vertex_size").toInt());
    ui_->openGLWidget->v_settings_->set_bg_color(
        settings_->value("background_color").toInt());
    ui_->openGLWidget->v_settings_->set_projection(
        settings_->value("type_projection").toInt());
  } else {
    ui_->parallel_button->click();
    ui_->solid_button->click();
    ui_->non_button->click();
  }
}

void s21::SettingMemento::setMementoState() {
  settings_->setValue("edges_type",
                      ui_->openGLWidget->v_settings_->get_facet_dased());
  settings_->setValue("edges_color",
                      ui_->openGLWidget->v_settings_->get_facet_color());
  settings_->setValue("edges_thickness",
                      ui_->openGLWidget->v_settings_->get_facet_thickness());
  settings_->setValue("vertix_display_method",
                      ui_->openGLWidget->v_settings_->get_vertex_shape());
  settings_->setValue("vertex_color",
                      ui_->openGLWidget->v_settings_->get_vertex_color());
  settings_->setValue("vertex_size",
                      ui_->openGLWidget->v_settings_->get_vertex_size());
  settings_->setValue("background_color",
                      ui_->openGLWidget->v_settings_->get_bg_color());
  settings_->setValue("type_projection",
                      ui_->openGLWidget->v_settings_->get_projection());
}

s21::SettingMemento::~SettingMemento() { delete settings_; }
