#ifndef ABC_H
#define ABC_H

#include <QObject>

class abc : public QObject
{
    Q_OBJECT
public:
    explicit abc(QObject *parent = nullptr);

signals:

};

#endif // ABC_H
