#include "room.h"
#include "ui_room.h"
#include <QPolygon>
#include <QPainter>

Room::Room(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
}

Room::~Room()
{
    delete ui;
}

const QString &Room::numberIdentifier() const
{
    return m_numberIdentifier;
}

void Room::setNumberIdentifier(const QString &newNumberIdentifier)
{
    m_numberIdentifier = newNumberIdentifier;
}

bool Room::allocated() const
{
    return m_allocated;
}

void Room::setAllocated(bool newAllocated)
{
    m_allocated = newAllocated;
}

Room::AllocationType Room::allocationType() const
{
    return m_allocationType;
}

void Room::setAllocationType(AllocationType newAllocationType)
{
    m_allocationType = newAllocationType;
}

int Room::numberOfOccupiers() const
{
    return m_numberOfOccupiers;
}

void Room::setNumberOfOccupiers(int newNumberOfOccupiers)
{
    m_numberOfOccupiers = newNumberOfOccupiers;
}

double Room::dayPrice() const
{
    return m_dayPrice;
}

void Room::setDayPrice(double newDayPrice)
{
    m_dayPrice = newDayPrice;
}

double Room::monthPrice() const
{
    return m_monthPrice;
}

void Room::setMonthPrice(double newMonthPrice)
{
    m_monthPrice = newMonthPrice;
}

Room::Type Room::type() const
{
    return m_type;
}

void Room::setType(Type newType)
{
    m_type = newType;
}

Room::Class Room::getClass() const
{
    return m_class;
}

void Room::setClass(Class newClass)
{
    m_class = newClass;
}

int Room::id() const
{
    return m_id;
}

void Room::setId(int newId)
{
    m_id = newId;
}

int Room::getFloor() const
{
    return floor;
}

void Room::setFloor(int newFloor)
{
    floor = newFloor;
}

// void Room::paintEvent(QPaintEvent *event)
// {

    // QPolygon roomDrawing;
    // roomDrawing << QPoint(0, 0);
    // roomDrawing << QPoint(40, 0);
    // roomDrawing << QPoint(40, 60);
    // roomDrawing << QPoint(0, 60);

    // QPen pen;
    // pen.setColor(Qt::blue);

    // QPainter painter(this);
    // painter.setPen(pen);
    // painter.drawPolygon(roomDrawing);
// }
