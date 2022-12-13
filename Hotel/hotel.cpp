#include "hotel.h"
#include "ui_hotel.h"
#include <QPolygon>
#include <QPainter>

Hotel::Hotel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hotel)
{
    ui->setupUi(this);
    m_id = 1;
    m_name = "HoHoHotel";
    m_numberOfFloors = 1;

    Room *room1 = new Room(this);
    room1->setId(1);
    room1->setNumberIdentifier("100");
    room1->setAllocated(true);
    room1->setNumberOfOccupiers(4);
    room1->setDayPrice(200);
    room1->setMonthPrice(4000);
    room1->setType(Room::Type::QUAD);
    room1->setClass(Room::Class::STANDARD);
    room1->setFloor(1);

    Room *room2 = new Room(this);
    room2->setId(2);
    room2->setNumberIdentifier("101");
    room2->setAllocated(false);
    room2->setNumberOfOccupiers(0);
    room2->setDayPrice(200);
    room2->setMonthPrice(4000);
    room2->setType(Room::Type::QUAD);
    room2->setClass(Room::Class::STANDARD);
    room2->setFloor(1);

    m_rooms.append(room1);
    m_rooms.append(room2);
}

Hotel::~Hotel()
{
    delete ui;
}

const QString &Hotel::name() const
{
    return m_name;
}

int Hotel::numberOfFloors() const
{
    return m_numberOfFloors;
}

int Hotel::numberOfRoomsOnFloor(int floor) const
{
    int roomsOnFloor = 0;
    for(Room* room : m_rooms)
    {
        if(room->getFloor() == floor)
        {
            ++roomsOnFloor;
        }
    }

    return roomsOnFloor;
}

// void Hotel::paintEvent(QPaintEvent *e)
// {
    // QPainter painter(this);
    // int x = 0;
    // int y = 0;
    // for(int i = 0; i < m_numberOfFloors; ++i)
    // {
        // QPolygon floor;
        // floor << QPoint(x, y);
        // floor << QPoint(x + 400, y);
        // floor << QPoint(x + 400, y + 100);
        // floor << QPoint(x, y + 100);

        // painter.drawPolygon(floor);

        // x += 400;
        // y += 100;
    // }
// }
