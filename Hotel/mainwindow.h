#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hotel.h"
#include "roomtablemodel.h"
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_actionInsertRow_triggered();
    void on_actionDeleteRow_triggered();

private:
    Ui::MainWindow *ui;

    QList<Hotel*> m_hotels;
    Hotel *m_selectedHotel;
    //RoomTableModel *m_modelFromSelectedHotel;
    RoomTableModel *m_roomTableModel;
    QSortFilterProxyModel *m_filterProxyModel;



protected:
    // void paintEvent(QPaintEvent *e);
};
#endif // MAINWINDOW_H
