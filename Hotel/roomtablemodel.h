#ifndef ROOMTABLEMODEL_H
#define ROOMTABLEMODEL_H

#include <QAbstractTableModel>
// #include "roomtableitem.h"
#include "room.h"

class RoomTableModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit RoomTableModel(QObject *parent = nullptr);

    QModelIndex parent(const QModelIndex &index) const override;
    QModelIndex index(int row, int column,
                                 const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    Room *root();

private:
    int m_numberOfRows;
    int m_numberOfColumns;
    Room *m_roomRoot;
};

#endif // ROOMTABLEMODEL_H
