#ifndef BOOLEANDELEGATE_H
#define BOOLEANDELEGATE_H

#include <QStyledItemDelegate>
#include "booleanwidget.h"


class BooleanDelegate : public QStyledItemDelegate
{
    Q_OBJECT

private:
    BooleanWidget *m_editorBoolean;

public:
    explicit BooleanDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
};

#endif // BOOLEANDELEGATE_H
