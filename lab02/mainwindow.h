#endif // CENTERFRAME_H
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "centerframe.h"
#include <QMainWindow>

class QLabel;
class QComboBox;
class QSpinBox;
 class QToolButton;

 class MainWindow : public QMainWindow
 {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = 0);

  ~MainWindow();

  void createToolBar();
 public slots:
  void penStyleChangged(int index=0);

  void penColorChangged();

 private:
  CenterFrame *centerFrame;
  QLabel *styleLabel;
  QComboBox *styleComboBox;
  QLabel *widthLabel;
  QSpinBox *widthSpinBox;
  QToolButton *colorBtn;
  QToolButton *clearBtn;
  QToolButton *imgBtn;
 protected slots:
  void on_colorBtn_clicked();
 private:
  void createToolBar();
  void createUserClient();
 };
 #endif // MAINWINDOW_H
