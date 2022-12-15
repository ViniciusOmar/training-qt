#include "roomtableitem.h"
#include <QDebug>

RoomTableItem::RoomTableItem(const QList<QVariant> &data, QList<RoomTableItem*> *parent) :
    m_roomData(data), m_parent(parent)
{

}

bool RoomTableItem::setData(int column, const QVariant &value)
{
    if(column < 0 || column >= m_roomData.size())
    {
        qDebug() << "RoomTableItem << setData << Message: Couldn't set data! Invalid Column";
        return false;
    }

    m_roomData[column] = value;
    return true;
}

QVariant RoomTableItem::getData(int column) const
{
    return m_roomData.at(column);
}

int RoomTableItem::columnCount() const
{
    return m_roomData.size();
}

int RoomTableItem::row() const
{
    if(m_parent)
    {
        return m_parent->indexOf( const_cast<RoomTableItem*>(this) );
    }

    return -1;
}

QList<RoomTableItem *> RoomTableItem::getParent() const
{
    return m_parent;
}
