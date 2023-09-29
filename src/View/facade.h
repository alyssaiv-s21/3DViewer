#ifndef CPP4_3DVIEWER_V2_0_VIEW_FACADE_H
#define CPP4_3DVIEWER_V2_0_VIEW_FACADE_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include "qlview.h"

namespace Ui {
class MainWindow;
}

namespace s21 {

/// @brief Class contains all variables and methods for GIF creating
class GifFacade : public QObject {
  Q_OBJECT
 public:
  GifFacade(QWidget *ui, Ui::MainWindow *glv);
  void make_gif();

 private slots:
  void save_one_pic();

 private:
  void select_dir();
  void save_gif();

  QWidget *ui_;
  Ui::MainWindow *glv_;
  int start_time_ = 0;
  int current_time_ = 100;
  int pic_qty_ = 1;
  QString pic_path_;
  QTimer *timer_ = nullptr;
};
}  // namespace s21

#endif  // #ifndef CPP4_3DVIEWER_V2_0_VIEW_FACADE_H
