#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QPainter>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QComboBox *hotels = new QComboBox(this);
    Hotel *hotel = new Hotel(this);
    m_selectedHotel = hotel;
    hotels->addItem(hotel->name(), QVariant::fromValue(hotel));

    QWidget *spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    ui->toolBar->addWidget(spacer);
    ui->toolBar->addWidget(hotels);
    ui->hotelWidget->setVisible(true);
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
