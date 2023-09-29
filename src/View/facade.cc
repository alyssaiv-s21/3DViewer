#include "facade.h"

#include "../gif.h"
#include "ui_mainwindow.h"

s21::GifFacade::GifFacade(QWidget *ui, Ui::MainWindow *glv)
    : ui_(ui), glv_(glv) {}

void s21::GifFacade::make_gif() { select_dir(); }

void s21::GifFacade::select_dir() {  
  pic_path_ = QDir::currentPath() + "/" + "folder_for_pic";
  QDir().mkdir(pic_path_);
  if (pic_path_ != "") {
    timer_ = new QTimer();
    QAbstractSpinBox::connect(timer_, SIGNAL(timeout()), this,
                              SLOT(save_one_pic()));
    timer_->start(100);
  }
}

void s21::GifFacade::save_one_pic() {
  if (start_time_ == current_time_ && pic_qty_ < 51) {
    glv_->openGLWidget->grab()
        .scaled(640, 480, Qt::IgnoreAspectRatio)
        .save(pic_path_ + "/" + QString::number(pic_qty_) + ".bmp");
    pic_qty_++;
    current_time_ += 100;
  }
  if (pic_qty_ > 50) {
    timer_->stop();
    save_gif();
    pic_qty_ = 1;
  }
  start_time_ += 100;
}

void s21::GifFacade::save_gif() {
  QString gif_name = QFileDialog::getSaveFileName(
      ui_, QObject::tr("Save gif"), "", QObject::tr("gif (*.gif)"));
  QByteArray ga = gif_name.toLocal8Bit();

  GifWriter writer = {};
  GifBegin(&writer, ga.data(), 640, 480, 10, 8, false);
  for (int i = 1; i <= 50; i++) {
    QImage img(pic_path_ + "/" + QString::number(i) + ".bmp");
    if (!img.isNull()) {
      if (GifWriteFrame(&writer,
                        img.convertToFormat(QImage::Format_Indexed8)
                            .convertToFormat(QImage::Format_RGBA8888)
                            .constBits(),
                        640, 480, 10, 8, false)) {
      } else {
        QMessageBox::critical(0, "Error", "Gif file can not be create!d");
        break;
      }
    } else {
      QMessageBox::critical(0, "Error", "Gif file can not be created!");
      break;
    }
  }
  GifEnd(&writer);
  QDir dir(pic_path_);
  dir.removeRecursively();
}
