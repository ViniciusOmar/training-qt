#ifndef BOOLEANWIDGET_H
#define BOOLEANWIDGET_H

#include <QWidget>
#include <QCheckBox>

class BooleanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BooleanWidget(QWidget *parent = nullptr);


    public:

    bool isChecked();
    void setChecked(bool value);

private:
    QCheckBox * checkBox;

signals:

};

#endif // BOOLEANWIDGET_H
