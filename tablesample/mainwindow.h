#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "activityfilter.h"
#include "activitymodel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_addButton_clicked();

  void on_removeButton_clicked();

  void on_lineEdit_textChanged(const QString &arg1);

private:
  Ui::MainWindow *ui;

  ActivityModel *m_model;
  ActivityFilter *m_proxyModel;
};
#endif // MAINWINDOW_H
