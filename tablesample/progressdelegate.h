#ifndef PROGRESSDELEGATE_H
#define PROGRESSDELEGATE_H

#include <QItemDelegate>
#include <QObject>

class ProgressDelegate : public QItemDelegate {
public:
  explicit ProgressDelegate(QObject *parent = nullptr);

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override;
};

#endif // PROGRESSDELEGATE_H
