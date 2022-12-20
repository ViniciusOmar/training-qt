#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QString>
#include <QMap>

class Room : public QObject
{
    Q_OBJECT

public:
    explicit Room(QObject *parent = nullptr);

    enum class Type { NONE, SINGLE, DOUBLE, TRIPLE, QUAD }; Q_ENUM(Type);
    enum class Class { NONE, STANDARD, MASTER, DELUXE }; Q_ENUM(Class);
    enum class AllocationType { NONE, DAY, MONTH }; Q_ENUM(AllocationType);

    const QString &numberIdentifier() const;
    void setNumberIdentifier(const QString &newNumberIdentifier);

    const bool &allocated() const;
    void setAllocated(bool newAllocated);

    const AllocationType &allocationType() const;
    void setAllocationType(AllocationType newAllocationType);

    const int &numberOfOccupiers() const;
    void setNumberOfOccupiers(int newNumberOfOccupiers);

    const double &dayPrice() const;
    void setDayPrice(double newDayPrice);

    const double &monthPrice() const;
    void setMonthPrice(double newMonthPrice);

    const Type &type() const;
    void setType(Type newType);
    const QString enumTypeToString(Type) const;

    const Class &getClass() const;
    void setClass(Class newClass);
    const QString enumClassToString(Class classEnum) const;

    const int &id() const;
    void setId(int newId);

    const int &floor() const;
    void setFloor(int newFloor);

    //Model related
    enum Columns
    {
        NUMBERIDENTIFIER,
        FLOOR,
        ALLOCATED,
        NUMBEROFOCCUPIERS,
        DAYPRICE,
        MONTHPRICE,
        TYPE,
        CLASS,
        NUMBEROFCOLUMNS
    };

    QVariant getData(int column) const;
    void addRootChild(Room* rootChild, int rowPosition);
    void removeRootChildAt(int row);
    QList<Room*> getRootChildren() const;
    Room *getRootChildAt(int row) const;

private:
    int m_id;
    QString m_numberIdentifier;

    bool m_allocated;
    AllocationType m_allocationType;
    int m_numberOfOccupiers;

    double m_dayPrice;
    double m_monthPrice;
    int m_roomFloor;

    Type m_type;
    Class m_class;

    //Model Related
    QList<Room*> m_rootChildren;
};

#endif // ROOM_H
