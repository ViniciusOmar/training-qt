#include "booleanwidget.h"
#include <QHBoxLayout>

BooleanWidget::BooleanWidget(QWidget *parent)
    : QWidget{parent}
{
    checkBox = new QCheckBox(this);
    QHBoxLayout * layout = new QHBoxLayout(this);
    layout->addWidget(checkBox, 0, Qt::AlignHCenter);
}

bool BooleanWidget::isChecked()
{
    return checkBox->isChecked();
}

void BooleanWidget::setChecked(bool value)
{
    checkBox->setChecked(value);
}
