#include "room.h"
#include <QPolygon>
#include <QPainter>
#include <QVariant>
#include <QMetaEnum>

Room::Room(QObject *parent) :
    QObject{parent}
{
    m_numberIdentifier = "";
    m_numberOfOccupiers = 0;
    m_allocated = false;
    m_dayPrice = 0;
    m_monthPrice = 0;
    m_roomFloor = 0;

    m_allocationType = Room::AllocationType::NONE;
    m_type = Room::Type::NONE;
    m_class = Room::Class::NONE;
}

//Getters and Setters
const QString &Room::numberIdentifier() const { return m_numberIdentifier; }
void Room::setNumberIdentifier(const QString &newNumberIdentifier) { m_numberIdentifier = newNumberIdentifier; }

const bool& Room::allocated() const { return m_allocated; }
void Room::setAllocated(bool newAllocated) { m_allocated = newAllocated; }

const Room::AllocationType& Room::allocationType() const { return m_allocationType; }
void Room::setAllocationType(AllocationType newAllocationType) { m_allocationType = newAllocationType; }

const int& Room::numberOfOccupiers() const { return m_numberOfOccupiers; }
void Room::setNumberOfOccupiers(int newNumberOfOccupiers) { m_numberOfOccupiers = newNumberOfOccupiers; }

const double& Room::dayPrice() const { return m_dayPrice; }
void Room::setDayPrice(double newDayPrice) { m_dayPrice = newDayPrice; }

const double& Room::monthPrice() const { return m_monthPrice; }
void Room::setMonthPrice(double newMonthPrice) { m_monthPrice = newMonthPrice; }

const Room::Type & Room::type() const { return m_type; }
void Room::setType(Type newType) { m_type = newType; }
const QString Room::enumTypeToString(Type typeEnum) const
{
    switch(typeEnum)
    {
        case Type::NONE:
            return "";
        case Type::SINGLE:
            return "Single";
        case Type::DOUBLE:
            return "Double";
        case Type::TRIPLE:
            return "Triple";
        case Type::QUAD:
            return "Quad";
        default:
            return "";
    }
}

const Room::Class & Room::getClass() const { return m_class; }
void Room::setClass(Class newClass) { m_class = newClass; }
const QString Room::enumClassToString(Class classEnum) const
{
    switch(classEnum)
    {
        case Class::NONE:
            return "";
        case Class::STANDARD:
            return "Standard";
        case Class::MASTER:
            return "Master";
        case Class::DELUXE:
            return "Deluxe";
        default:
            return "";
    }
}


const int& Room::id() const { return m_id; }
void Room::setId(int newId) { m_id = newId; }

const int& Room::floor() const { return m_roomFloor; }
void Room::setFloor(int newFloor) { m_roomFloor = newFloor; }

//Model Related
QVariant Room::getData(int column) const
{
    switch(column)
    {
        case Room::NUMBERIDENTIFIER:
            return numberIdentifier();
        case Room::ALLOCATED:
            return allocated();
        case Room::FLOOR:
            return floor();
        case Room::NUMBEROFOCCUPIERS:
            return numberOfOccupiers();
        case Room::DAYPRICE:
            return dayPrice();
        case Room::MONTHPRICE:
            return monthPrice();
        case Room::TYPE:
            // return QMetaEnum::fromType<Room::Type>().valueToKey(static_cast<int>(type()));
            // return QVariant::fromValue(type());
            return enumTypeToString(type());
        case Room::CLASS:
            // return QVariant::fromValue(getClass());
            return enumClassToString(getClass());
        default:
            break;
    }

    return QVariant();
}

void Room::addRootChild(Room* newRootChild, int position)
{
    m_rootChildren.insert(position, newRootChild);
    newRootChild->setParent(this);
}
void Room::removeRootChildAt(int row)
{
    m_rootChildren.removeAt(row);
}

QList<Room*> Room::getRootChildren() const
{
    return m_rootChildren;
}
Room* Room::getRootChildAt(int row) const
{
    return m_rootChildren.at(row);
}
