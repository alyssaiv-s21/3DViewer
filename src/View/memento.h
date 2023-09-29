#ifndef CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_H
#define CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_H

#include <QSettings>

namespace Ui {
class MainWindow;
}

namespace s21 {

/// @brief Class for saving visual settings
class SettingMemento {
 public:
  explicit SettingMemento(Ui::MainWindow *ui);
  ~SettingMemento();
  void getMementoState();
  void setMementoState();

 private:
  SettingMemento(const SettingMemento &) = delete;
  void operator=(const SettingMemento &) = delete;
  QSettings *settings_;
  Ui::MainWindow *ui_;
};
}  // namespace s21

#endif  // #ifndef CPP4_3DVIEWER_V2_0_VIEW_MEMENTO_H
