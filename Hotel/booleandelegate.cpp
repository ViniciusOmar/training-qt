#include "booleandelegate.h"
#include <QCheckBox>
#include <QStyleOptionButton>
#include <QEvent>
#include <QMouseEvent>
#include <QAbstractItemView>
#include <QHBoxLayout>

BooleanDelegate::BooleanDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *BooleanDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return new BooleanWidget(parent);
}

void BooleanDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    bool value = index.data().toBool();
    BooleanWidget *editorCheckBox = static_cast<BooleanWidget*>(editor);
    editorCheckBox->setChecked(value);
}

void BooleanDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    BooleanWidget *editorCheckBox = static_cast<BooleanWidget*>(editor);
    model->setData(index, editorCheckBox->isChecked(), Qt::EditRole);
}


void BooleanDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    QStyleOptionButton checkBox;

    checkBox.rect = option.widget->style()->subElementRect(QStyle::SE_CheckBoxClickRect, &checkBox, 0);
    const int x = option.rect.center().x() - checkBox.rect.width()/2;
    const int y = option.rect.center().y() - checkBox.rect.height()/2;
    checkBox.rect.moveTo(x, y);

    bool isChecked = index.data().toBool();
    if(isChecked)
    {
        checkBox.state |= QStyle::State_On;
        checkBox.state |= QStyle::State_Enabled;
    }
    else
    {
        checkBox.state |= QStyle::State_Off;
    }

    option.widget->style()->drawControl(QStyle::CE_CheckBox, &checkBox, painter, 0);
}


bool BooleanDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event == nullptr)
    {
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    if(event->type() != QEvent::MouseButtonRelease)
    {
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if(mouseEvent->button() != Qt::LeftButton)
    {
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    bool currentValue = index.data().toBool();
    model->setData(index, !currentValue, Qt::EditRole);

    return true;
}
