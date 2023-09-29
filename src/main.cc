#include <QApplication>

#include "View/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::ViewerModel model;
  s21::ViewerController controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
