#ifndef ROOMCLASSDELEGATE_H
#define ROOMCLASSDELEGATE_H

#include <QStyledItemDelegate>
#include "room.h"

class RoomClassDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit RoomClassDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
    // void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:
    QMap<Room::Class, QString> m_roomClass;
};

#endif // ROOMCLASSDELEGATE_H
