#ifndef ROOMTYPEDELEGATE_H
#define ROOMTYPEDELEGATE_H

#include <QStyledItemDelegate>
#include "room.h"

class RoomTypeDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit RoomTypeDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QString toEnumText(QString enumText) const;
private:
    QMap<Room::Type, QString> m_enumTypes;
};

#endif // ROOMTYPEDELEGATE_H
