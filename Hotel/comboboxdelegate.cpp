#include "comboboxdelegate.h"
#include <QComboBox>
#include <QMap>
#include <QDebug>
#include <QVariant>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    m_enumTypes.insert("Single", Room::Type::SINGLE);
    m_enumTypes.insert("Double", Room::Type::DOUBLE);
    m_enumTypes.insert("Triple", Room::Type::TRIPLE);
    m_enumTypes.insert("Quad", Room::Type::QUAD);
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return new QComboBox(parent);
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    Q_UNUSED(index);
    QComboBox* editorComboBox = static_cast<QComboBox*>(editor);
    for(auto value : m_enumTypes)
    {
        editorComboBox->addItem(m_enumTypes.key(value), QVariant::fromValue(value).toInt());
    }

    editorComboBox->showPopup();
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* editorComboBox = static_cast<QComboBox*>(editor);
    model->setData(index, editorComboBox->currentData(), Qt::EditRole);
}
