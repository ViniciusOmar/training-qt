#ifndef ROOMTABLEMODEL_H
#define ROOMTABLEMODEL_H

#include <QAbstractTableModel>
// #include "roomtableitem.h"
#include "room.h"

class RoomTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RoomTableModel(QObject *parent = nullptr);

    //Create index for every cell
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    //Make model class functional, base functions
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //Make cells editable
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    //Make possible to add and remove rows
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    int m_numberOfRows;
    int m_numberOfColumns;
    Room *m_roomRoot;
};

#endif // ROOMTABLEMODEL_H
