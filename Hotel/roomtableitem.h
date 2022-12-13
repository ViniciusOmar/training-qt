#ifndef ROOMTABLEITEM_H
#define ROOMTABLEITEM_H

#include <QVariant>

class RoomTableItem
{
public:
    RoomTableItem(const QList<QVariant>&data, RoomTableItem *parent = nullptr);

    bool setData(int column, const QVariant &value);
    QList<QVariant> getData() const;

    int columnCount() const;
    int insertColumn(int position, int columns);

    int row() const;

private:
    QList<QVariant> m_roomData;
    RoomTableItem *m_parent;
};

#endif // ROOMTABLEITEM_H
