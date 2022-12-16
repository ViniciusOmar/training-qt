#ifndef HOTEL_H
#define HOTEL_H

#include <QWidget>
#include <QDebug>
#include "room.h"
#include "roomtablemodel.h"

namespace Ui {
class Hotel;
}

class Hotel : public QWidget
{
    Q_OBJECT
public:
    explicit Hotel(QWidget *parent = nullptr);
    ~Hotel();

    QList<Hotel> getHotelsFromJson();

    const QString &name() const;

    int numberOfFloors() const;
    int numberOfRoomsOnFloor(int floor) const;

    RoomTableModel *getRoomTableModel() const;

private:
    Ui::Hotel *ui;

    int m_id;
    QString m_name;

    int m_numberOfFloors;
    QList<Room*> m_rooms;

    double income;

protected:
    // void paintEvent(QPaintEvent *e);
};

Q_DECLARE_METATYPE(Hotel*)

#endif // HOTEL_H
