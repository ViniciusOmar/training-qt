#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QPainter>
#include <QStandardItemModel>
#include <QTableView>

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

    ui->toolBar->addWidget(spacer);
    ui->toolBar->addWidget(hotels);

    ui->hotelWidget->setVisible(true);
    ui->tableView->setModel(m_roomTableModel);

    setCentralWidget(ui->hotelWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::paintEvent(QPaintEvent *e)
// {
    // QPainter painter(this);
    // int numberOfFloors = m_selectedHotel->numberOfFloors();
    // int minHorizontalSize = 400;
    // int verticalSize = 100;
    // for(int i = 0; i < numberOfFloors; ++i)
    // {
        // int numberOfRoomsOnThisFloor = m_selectedHotel->numberOfRoomsOnFloor(i);
        // for(int j = 0; j < numberOfRoomsOnThisFloor; ++j)
        // {

        // }
    // }
// }

void MainWindow::on_actionInsertRow_triggered()
{
    m_roomTableModel->insertRow(0, QModelIndex());
}
