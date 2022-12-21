#include "roomclassdelegate.h"
#include <QComboBox>
#include <QMetaEnum>
#include <QEvent>
#include <QMouseEvent>
#include <QAbstractItemView>
#include <QStyleOptionComboBox>

RoomClassDelegate::RoomClassDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    m_roomClass.insert(Room::Class::NONE, "");
    m_roomClass.insert(Room::Class::STANDARD, "Standard");
    m_roomClass.insert(Room::Class::MASTER, "Master");
    m_roomClass.insert(Room::Class::DELUXE, "Deluxe");
}


QWidget *RoomClassDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return new QComboBox(parent);
}

void RoomClassDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *roomClassEditor = static_cast<QComboBox*>(editor);
    for(auto classEnumText : m_roomClass)
    {
        auto classEnumValue = m_roomClass.key(classEnumText);
        roomClassEditor->addItem(classEnumText, QVariant::fromValue(classEnumValue));
    }

    QString currentClassEnumText = index.data(Qt::DisplayRole).toString();
    int currentClassEnumValue = QMetaEnum::fromType<Room::Class>().keyToValue(currentClassEnumText.toUpper().toUtf8());
    int roomEditorIndex = roomClassEditor->findData(currentClassEnumValue);
    roomClassEditor->setCurrentIndex(roomEditorIndex);

    roomClassEditor->showPopup();
}

void RoomClassDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *roomClassEditor = static_cast<QComboBox*>(editor);
    auto currentRoomClassEditorData = roomClassEditor->currentData(Qt::UserRole);
    model->setData(index, currentRoomClassEditorData, Qt::EditRole);
}


bool RoomClassDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            auto currentView = qobject_cast<QAbstractItemView*>(const_cast<QWidget*>(option.widget));
            if(currentView != nullptr)
            {
                currentView->setCurrentIndex(index);
                currentView->edit(index);
            }

            return true;
        }

    }

    return QAbstractItemDelegate::editorEvent(event, model, option, index);
}

void RoomClassDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    QStyleOptionComboBox comboBoxVisual;
    comboBoxVisual.rect = option.rect;
    comboBoxVisual.state = option.state;

    comboBoxVisual.currentText = index.data().toString();
    option.widget->style()->drawComplexControl(QStyle::CC_ComboBox, &comboBoxVisual, painter, 0);
    option.widget->style()->drawControl(QStyle::CE_ComboBoxLabel, &comboBoxVisual, painter, 0);
}

// inline
