#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QPainter>
#include <QStandardItemModel>
#include <QTableView>
#include <QMessageBox>
#include "roomtypedelegate.h"
#include "roomclassdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_selectedHotel(new Hotel(this))

{
    ui->setupUi(this);

    QComboBox *hotels = new QComboBox(this);
    hotels->addItem(m_selectedHotel->name(), QVariant::fromValue(m_selectedHotel));

    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    m_roomTableModel = new RoomTableModel(this);

    connect(ui->actionInsertRow, &QAction::triggered, this, &MainWindow::on_actionInsertRow_triggered);
    connect(ui->actionDeleteRow, &QAction::triggered, this, &MainWindow::on_actionDeleteRow_triggered);

    ui->toolBar->addWidget(spacer);
    ui->toolBar->addWidget(hotels);

    ui->hotelWidget->setVisible(true);
    ui->tableView->setModel(m_roomTableModel);
    ui->tableView->setItemDelegateForColumn(6, new RoomTypeDelegate(this));
    ui->tableView->setItemDelegateForColumn(7, new RoomClassDelegate(this));

    setCentralWidget(ui->hotelWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionInsertRow_triggered()
{
    QItemSelectionModel *rowSelection = ui->tableView->selectionModel();
    int row = m_roomTableModel->rowCount();

    if(rowSelection->hasSelection())
    {
        row = rowSelection->currentIndex().row() + 1;
    }

    m_roomTableModel->insertRow(row, QModelIndex());
}

void MainWindow::on_actionDeleteRow_triggered()
{
    QItemSelectionModel *rowSelection = ui->tableView->selectionModel();

    if(!rowSelection->hasSelection())
    {
        QMessageBox::warning(this, tr("Warning"), tr("It's necessary to select a row for deletion!"));
        return;
    }

    QModelIndex rowIndex = rowSelection->currentIndex();
    m_roomTableModel->removeRow(rowIndex.row(), QModelIndex());
}
