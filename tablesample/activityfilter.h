#ifndef ACTIVITYFILTER_H
#define ACTIVITYFILTER_H

#include <QObject>
#include <QSortFilterProxyModel>

class ActivityFilter : public QSortFilterProxyModel {
  Q_OBJECT
public:
  ActivityFilter(QObject *parent = nullptr);
};

#endif // ACTIVITYFILTER_H
