#include "activity.h"

Activity::Activity(QObject *parent) : QObject{parent}, m_progress(0) {}

const QString &Activity::code() const { return m_code; }
void Activity::setCode(const QString &newCode) { m_code = newCode; }

const QString &Activity::name() const { return m_name; }
void Activity::setName(const QString &newName) { m_name = newName; }

Activity *Activity::parent() const { return m_parent; }
void Activity::setParent(Activity *newParent) { m_parent = newParent; }

const QList<Activity *> &Activity::children() const { return m_children; }

const QDateTime &Activity::planStart() const { return m_planStart; }
void Activity::setPlanStart(const QDateTime &newPlanStart) {
  m_planStart = newPlanStart;
}

const QDateTime &Activity::planEnd() const { return m_planEnd; }
void Activity::setPlanEnd(const QDateTime &newPlanEnd) {
  m_planEnd = newPlanEnd;
}

const QDateTime &Activity::realStart() const { return m_realStart; }
void Activity::setRealStart(const QDateTime &newRealStart) {
  m_realStart = newRealStart;
}

const QDateTime &Activity::realEnd() const { return m_realEnd; }
void Activity::setRealEnd(const QDateTime &newRealEnd) {
  m_realEnd = newRealEnd;
}

void Activity::addChild(Activity *child, int index) {
  m_children.insert(index, child);
  child->setParent(this);
}

void Activity::removeChild(Activity *child) { m_children.removeOne(child); }
void Activity::removeChildAt(int index) { m_children.removeAt(index); }

double Activity::progress() const { return m_progress; }
void Activity::setProgress(double newProgress) { m_progress = newProgress; }
