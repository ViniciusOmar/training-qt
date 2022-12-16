#ifndef ROOMTABLEITEM_H
#define ROOMTABLEITEM_H

#include <QVariant>
#include <QAbstractTableModel>

class RoomTableItem
{
public:
    RoomTableItem(const QList<QVariant>&data, QList<RoomTableItem*> *parent = nullptr);

    private:
};

#endif // ROOMTABLEITEM_H
