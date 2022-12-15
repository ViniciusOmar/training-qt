#ifndef ACTIVITYMODEL_H
#define ACTIVITYMODEL_H

#include "activity.h"
#include <QAbstractItemModel>

class ActivityModel : public QAbstractItemModel {
  Q_OBJECT

public:
  explicit ActivityModel(QObject *parent = nullptr);

  // Basic functionality:
  QModelIndex index(int row, int column,
                    const QModelIndex &parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex &index) const override;

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

  // Editable:
  bool setData(const QModelIndex &index, const QVariant &value,
               int role = Qt::EditRole) override;

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  // Add data:
  bool insertRows(int row, int count,
                  const QModelIndex &parent = QModelIndex()) override;

  // Remove data:
  bool removeRows(int row, int count,
                  const QModelIndex &parent = QModelIndex()) override;

private:
  Activity *m_root;
};

#endif // ACTIVITYMODEL_H
