#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hotel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QList<Hotel*> m_hotels;
    Hotel *m_selectedHotel;

protected:
    /*void paintEvent(QPaintEvent *e);*/
};
#endif // MAINWINDOW_H
