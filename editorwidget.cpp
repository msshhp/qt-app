#include "editorwidget.h"

#include <QVBoxLayout>

EditorWidget::EditorWidget(QWidget* parent)
    : QWidget(parent)
    , checkBox(new QCheckBox)
    , lineBox(new QLineEdit)
    , comboBox(new QComboBox)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    comboBox->addItems({ "item1", "item2", "item3" });
    layout->addWidget(checkBox);
    layout->addWidget(lineBox);
    layout->addWidget(comboBox);
}
