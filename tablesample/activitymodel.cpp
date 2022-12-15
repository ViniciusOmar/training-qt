#include "activitymodel.h"

ActivityModel::ActivityModel(QObject *parent)
    : QAbstractItemModel(parent), m_root(new Activity(this)) {}

QModelIndex ActivityModel::index(int row, int column,
                                 const QModelIndex &parent) const {
  if (!hasIndex(row, column, parent))
    return QModelIndex();

  if (!parent.isValid()) {
    auto item = m_root->children().at(row);
    return createIndex(row, column, item);
  }

  auto parentItem = static_cast<Activity *>(parent.internalPointer());
  auto item = parentItem->children().at(row);
  return createIndex(row, column, item);
}

QModelIndex ActivityModel::parent(const QModelIndex &index) const {
  if (!index.isValid())
    return QModelIndex();
  auto item = static_cast<Activity *>(index.internalPointer());

  auto parent = item->parent();
  if (parent == m_root)
    return QModelIndex();

  auto grandParent = parent->parent();
  auto row = grandParent->children().indexOf(parent);

  return createIndex(row, 0, parent);
}

int ActivityModel::rowCount(const QModelIndex &parent) const {
  if (!parent.isValid())
    return m_root->children().count();

  auto parentItem = static_cast<Activity *>(parent.internalPointer());
  int count = parentItem->children().count();
  return count;
}

int ActivityModel::columnCount(const QModelIndex &parent) const {
  return Activity::ColumnCount;
}

QVariant ActivityModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const {
  if (role != Qt::DisplayRole)
    return QAbstractItemModel::headerData(section, orientation, role);

  if (orientation == Qt::Vertical)
    return QVariant();

  switch (section) {
  case Activity::Code:
    return tr("Code");
  case Activity::Name:
    return tr("Name");
  case Activity::PlanStart:
    return tr("Planned Start");
  case Activity::PlanEnd:
    return tr("Planned End");
  case Activity::RealStart:
    return tr("Real Start");
  case Activity::RealEnd:
    return tr("Real End");
  case Activity::Progress:
    return tr("Progress");
  default:
    break;
  }

  return QVariant();
}

QVariant ActivityModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  auto item = static_cast<Activity *>(index.internalPointer());
  switch (role) {
  case Qt::DisplayRole:
  case Qt::EditRole:
    switch (index.column()) {
    case Activity::Code:
      return item->code();
    case Activity::Name:
      return item->name();
    case Activity::PlanStart:
      return item->planStart();
    case Activity::PlanEnd:
      return item->planEnd();
    case Activity::RealStart:
      return item->realStart();
    case Activity::RealEnd:
      return item->realEnd();
    case Activity::Progress:
      return item->progress();
    default:
      break;
    }
    break;
  default:
    break;
  }
  return QVariant();
}

bool ActivityModel::setData(const QModelIndex &index, const QVariant &value,
                            int role) {
  if (!index.isValid())
    return false;
  auto item = static_cast<Activity *>(index.internalPointer());
  if (data(index, role) != value) {
    switch (index.column()) {
    case Activity::Code:
      item->setCode(value.toString());
      break;
    case Activity::Name:
      item->setName(value.toString());
      break;
    case Activity::PlanStart:
      item->setPlanStart(value.toDateTime());
      break;
    case Activity::PlanEnd:
      item->setPlanEnd(value.toDateTime());
      break;
    case Activity::RealStart:
      item->setRealStart(value.toDateTime());
      break;
    case Activity::RealEnd:
      item->setRealEnd(value.toDateTime());
      break;
    case Activity::Progress:
      item->setProgress(value.toDouble());
      break;
    default:
      break;
    }
    emit dataChanged(index, index, {role});
    return true;
  }
  return false;
}

Qt::ItemFlags ActivityModel::flags(const QModelIndex &index) const {
  if (!index.isValid())
    return Qt::NoItemFlags;

  //  switch (index.column()) {
  //  case Activity::PlanStart:
  //  case Activity::PlanEnd:
  //  case Activity::RealStart:
  //  case Activity::RealEnd:
  //    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
  //    break;
  //  default:
  //    break;
  //  }

  return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ActivityModel::insertRows(int row, int count, const QModelIndex &parent) {
  Activity *parentItem;
  if (!parent.isValid())
    parentItem = m_root;
  else
    parentItem = static_cast<Activity *>(parent.internalPointer());
  beginInsertRows(parent, row, row + count - 1);
  for (int i = 0; i < count; ++i) {
    auto newActivity = new Activity(parentItem);
    parentItem->addChild(newActivity, row + i);
    if (parentItem != m_root)
      newActivity->setCode(parentItem->code() + "." +
                           QString::number(parentItem->children().count()));
    else
      newActivity->setCode(QString::number(parentItem->children().count()));
  }
  endInsertRows();
  return true;
}

bool ActivityModel::removeRows(int row, int count, const QModelIndex &parent) {
  Activity *parentItem;
  if (!parent.isValid())
    parentItem = m_root;
  else
    parentItem = static_cast<Activity *>(parent.internalPointer());
  beginRemoveRows(parent, row, row + count - 1);
  for (int i = 0; i < count; ++i)
    parentItem->removeChildAt(row);
  endRemoveRows();
  return true;
}
