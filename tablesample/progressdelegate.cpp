#include "progressdelegate.h"
#include <QDoubleSpinBox>
#include <QPainter>

ProgressDelegate::ProgressDelegate(QObject *parent) : QItemDelegate{parent} {}

void ProgressDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const {
  painter->save();

  auto progress = index.data().toDouble();

  if (progress < 50)
    painter->setPen(Qt::blue);
  else
    painter->setPen(Qt::green);

  painter->setBackground(option.backgroundBrush);

  auto rect = option.rect;
  painter->drawText(rect, QString::number(progress, 'f', 2) + "%");

  painter->restore();
}

QWidget *ProgressDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const {
  Q_UNUSED(option)
  Q_UNUSED(index)
  auto *editor = new QDoubleSpinBox(parent);
  editor->setMaximum(100);
  editor->setMinimum(0);
  editor->setDecimals(2);
  editor->setValue(index.data().toDouble());
  return editor;
}
