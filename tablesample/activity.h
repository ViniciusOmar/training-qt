#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QDateTime>
#include <QObject>

class Activity : public QObject {
  Q_OBJECT
public:
  enum Columns {
    Code,
    Name,
    PlanStart,
    PlanEnd,
    RealStart,
    RealEnd,
    Progress,
    ColumnCount
  };
  Q_ENUM(Columns)

  explicit Activity(QObject *parent = nullptr);

  const QString &code() const;
  void setCode(const QString &newCode);

  const QString &name() const;
  void setName(const QString &newName);

  Activity *parent() const;
  void setParent(Activity *newParent);

  const QList<Activity *> &children() const;

  const QDateTime &planStart() const;
  void setPlanStart(const QDateTime &newPlanStart);

  const QDateTime &planEnd() const;
  void setPlanEnd(const QDateTime &newPlanEnd);

  const QDateTime &realStart() const;
  void setRealStart(const QDateTime &newRealStart);

  const QDateTime &realEnd() const;
  void setRealEnd(const QDateTime &newRealEnd);

  void addChild(Activity *child, int index);

  void removeChild(Activity *child);

  void removeChildAt(int index);

  double progress() const;
  void setProgress(double newProgress);

private:
  QString m_code;
  QString m_name;
  Activity *m_parent;
  QList<Activity *> m_children;
  QDateTime m_planStart;
  QDateTime m_planEnd;
  QDateTime m_realStart;
  QDateTime m_realEnd;
  double m_progress;
};

#endif // ACTIVITY_H
