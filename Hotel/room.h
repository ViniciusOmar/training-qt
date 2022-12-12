#ifndef ROOM_H
#define ROOM_H

#include <QWidget>

namespace Ui {
class Room;
}

class Room : public QWidget
{
    Q_OBJECT

public:
    explicit Room(QWidget *parent = nullptr);
    ~Room();

    enum Type { SINGLE, DOUBLE, TRIPLE, QUAD };
    enum Class { STANDARD, MASTER, DELUXE };
    enum AllocationType { NONE, DAY, MONTH };

    const QString &numberIdentifier() const;
    void setNumberIdentifier(const QString &newNumberIdentifier);

    bool allocated() const;
    void setAllocated(bool newAllocated);

    AllocationType allocationType() const;
    void setAllocationType(AllocationType newAllocationType);

    int numberOfOccupiers() const;
    void setNumberOfOccupiers(int newNumberOfOccupiers);

    double dayPrice() const;
    void setDayPrice(double newDayPrice);

    double monthPrice() const;
    void setMonthPrice(double newMonthPrice);

    Type type() const;
    void setType(Type newType);

    Class getClass() const;
    void setClass(Class newClass);

    int id() const;
    void setId(int newId);

    int getFloor() const;
    void setFloor(int newFloor);


private:
    Ui::Room *ui;

    int m_id;
    QString m_numberIdentifier;

    bool m_allocated;
    AllocationType m_allocationType;
    int m_numberOfOccupiers;

    double m_dayPrice;
    double m_monthPrice;
    int floor;

    Type m_type;
    Class m_class;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // ROOM_H
