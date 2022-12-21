#include "roomtypedelegate.h"
#include <QComboBox>
#include <QMap>
#include <QDebug>
#include <QVariant>
#include <QMetaEnum>
#include <QEvent>
#include <QApplication>
#include <QMouseEvent>
#include <QAbstractItemView>
#include <QStyledItemDelegate>


RoomTypeDelegate::RoomTypeDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    m_enumTypes.insert(Room::Type::NONE, "");
    m_enumTypes.insert(Room::Type::SINGLE, "Single");
    m_enumTypes.insert(Room::Type::DOUBLE, "Double");
    m_enumTypes.insert(Room::Type::TRIPLE, "Triple");
    m_enumTypes.insert(Room::Type::QUAD, "Quad");
}

QWidget *RoomTypeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return new QComboBox(parent);
}

void RoomTypeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* editorComboBox = static_cast<QComboBox*>(editor);
    for(auto &enumText : m_enumTypes)
    {
        editorComboBox->addItem(enumText, QVariant::fromValue(m_enumTypes.key(enumText)));
    }

    QString enumCurrentText = toEnumText(index.data().toString());
    int enumCurrentValue = QMetaEnum::fromType<Room::Type>().keyToValue(enumCurrentText.toUtf8());
    int comboBoxIndex = editorComboBox->findData(enumCurrentValue, Qt::UserRole);

    if(comboBoxIndex >= 0)
    {
        editorComboBox->setCurrentIndex(comboBoxIndex);
    }

    editorComboBox->showPopup();
}

void RoomTypeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* editorComboBox = static_cast<QComboBox*>(editor);
    model->setData(index, editorComboBox->currentData(), Qt::EditRole);
}

bool RoomTypeDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            QAbstractItemView* currentView = qobject_cast<QAbstractItemView*>( const_cast<QWidget*>(option.widget) );
            if(currentView != nullptr)
            {
                currentView->setCurrentIndex(index);
                currentView->edit(index);
            }
            return true;
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void RoomTypeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionComboBox box;
    box.state = option.state;
    box.rect = option.rect;

    box.styleObject = option.styleObject;
    box.currentText = index.data(Qt::EditRole).toString();

    option.widget->style()->drawComplexControl(QStyle::CC_ComboBox, &box, painter, 0);
    option.widget->style()->drawControl(QStyle::CE_ComboBoxLabel, &box, painter, 0);
    return;
}

QString RoomTypeDelegate::toEnumText(QString enumText) const //Returns a string that is equal to the enum text pattern
{
    QString key = enumText.toUpper();
    if(key == "")
    {
        key = "NONE";
    }

    return key;
}
