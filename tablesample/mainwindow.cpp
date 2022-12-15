#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "activityfilter.h"
#include "progressdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  m_model = new ActivityModel(this);
  m_proxyModel = new ActivityFilter(this);
  m_proxyModel->setSourceModel(m_model);
  auto delegate = new ProgressDelegate(this);
  ui->treeView->setModel(m_proxyModel);
  ui->treeView->setHeaderHidden(false);
  ui->treeView->setItemDelegateForColumn(Activity::Progress, delegate);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_addButton_clicked() {
  auto selected = ui->treeView->selectionModel()->selectedRows();
  if (selected.isEmpty())
    m_model->insertRow(0, QModelIndex());
  else {
    auto index = m_proxyModel->mapToSource(selected.first());
    m_model->insertRow(0, index);
  }
}

void MainWindow::on_removeButton_clicked() {
  auto selected = ui->treeView->selectionModel()->selectedRows();
  if (selected.isEmpty())
    return;

  auto index = m_proxyModel->mapToSource(selected.first());
  m_model->removeRow(index.row(), index.parent());
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) {
  m_proxyModel->setFilterRegExp(arg1);
}
