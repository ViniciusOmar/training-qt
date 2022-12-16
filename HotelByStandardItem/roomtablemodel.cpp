#include "roomtablemodel.h"
#include <QModelIndex>
#include <QDebug>

RoomTableModel::RoomTableModel(QObject *parent)
    : QAbstractItemModel(parent),
      m_numberOfRows(0),
      m_numberOfColumns(Room::NUMBEROFCOLUMNS),
      m_roomRoot(new Room(this))
{
}

QModelIndex RoomTableModel::index(int row, int column,
                                 const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    Room *item = m_roomRoot->getRootChildren().at(row);
    return createIndex(row, column, item);
}

QModelIndex RoomTableModel::parent(const QModelIndex &index) const
{
    qDebug() << "Index[" << index.row() << "][" << index.column() << "]";
    return QModelIndex();
}


int RoomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_numberOfRows;
}

int RoomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_numberOfColumns;
}

QVariant RoomTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    auto item = static_cast<Room*>(index.internalPointer());
    switch(role)
    {
        case Qt::DisplayRole: case Qt::EditRole:
            return item->getData(index.column());
            break;
        default:
            break;
    }

    return QVariant();
}

bool RoomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    int column = index.column();
    if(column >= Room::NUMBEROFCOLUMNS)
    {
        return false;
    }

    if (data(index, role) == value)
    {
        return false;
    }

    auto item = static_cast<Room*>(index.internalPointer());
    switch(column)
    {
        case Room::NUMBERIDENTIFIER:
            item->setNumberIdentifier(value.toString());
            break;
        case Room::ALLOCATED:
            item->setAllocated(value.toBool());
            break;
        case Room::FLOOR:
            item->setFloor(value.toUInt());
            break;
        case Room::DAYPRICE:
            item->setDayPrice(value.toDouble());
            break;
        case Room::MONTHPRICE:
            item->setMonthPrice(value.toDouble());
            break;
        case Room::NUMBEROFOCCUPIERS:
            item->setNumberOfOccupiers(value.toInt());
            break;
        case Room::TYPE:
            item->setType(static_cast<Room::Type>(value.toInt()));
            break;
        case Room::CLASS:
            item->setClass(static_cast<Room::Class>(value.toInt()));
            break;
        default:
            break;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags RoomTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant RoomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Orientation::Vertical)
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole)
    {
        switch(section)
        {
             case Room::NUMBERIDENTIFIER:
                return tr("Room Number");
                break;
            case Room::ALLOCATED:
                return tr("Allocated");
                break;
            case Room::FLOOR:
                return tr("Floor");
                break;
            case Room::NUMBEROFOCCUPIERS:
                return tr("Occupiers");
                break;
            case Room::DAYPRICE:
                return tr("Price per day");
                break;
            case Room::MONTHPRICE:
                return tr("Price per month");
                break;
            case Room::TYPE:
                return tr("Type");
                break;
            case Room::CLASS:
                return tr("Class");
                break;
            default:
                break;
        }
    }

    return QVariant();
}

bool RoomTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i = 0; i < count; ++i)
    {
        auto newRow = new Room(m_roomRoot);
        m_roomRoot->addRootChild(newRow, row + i);
        ++m_numberOfRows;
    }
    endInsertRows();
    return true;
}

bool RoomTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for(int i = 0; i < count; ++i)
    {
        delete m_roomRoot->getRootChildren().takeAt(row + i);
    }
    endRemoveRows();
    return true;
}
