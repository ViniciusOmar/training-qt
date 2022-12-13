#include "roomtableitem.h"

RoomTableItem::RoomTableItem(const QList<QVariant> &data, RoomTableItem *parent) :
    m_roomData(data), m_parent(parent)
{

}

QList<QVariant> RoomTableItem::getData() const
{
    return m_roomData;
}

int RoomTableItem::columnCount() const
{
    return m_roomData.size();
}
