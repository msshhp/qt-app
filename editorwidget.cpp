#include "editorwidget.h"
#include <QVBoxLayout>

EditorWidget::EditorWidget(QWidget* parent)
    : QWidget(parent)
    , pushButton(new QPushButton(this))
    , lineEdit(new QLineEdit(this))
    , dSpinBox(new QDoubleSpinBox(this))
{
    if (parent) {
        qDebug() << __FUNCTION__ << parent << parent->objectName() << this << this->objectName();
    }

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(pushButton);
    layout->addWidget(lineEdit);
    layout->addWidget(dSpinBox);
}

void EditorWidget::setPrice(const int& price)
{
    pushButton->setText(QString::number(price));
}

void EditorWidget::setPosition(const int& position)
{
    lineEdit->setText(QString::number(position));
}

int EditorWidget::getPosition() const
{
    return lineEdit->text().toInt();
}

void EditorWidget::setSize(const double& size)
{
    dSpinBox->setValue(size);
}

double EditorWidget::getSize() const
{
    return dSpinBox->value();
}
