#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

class EditorWidget : public QWidget {
    Q_OBJECT
public:
    explicit EditorWidget(QWidget* parent = nullptr);

    int currentIndex()
    {
        return comboBox->currentIndex();
    }
    void setCurrentIndex(int index)
    {
        comboBox->setCurrentIndex(index);
    }
    QString text() const
    {
        return lineBox->text();
    }
    void setText(const QString& text)
    {
        lineBox->setText(text);
    }
    Qt::CheckState checkState() const
    {
        return checkBox->checkState();
    }
    void setCheckState(Qt::CheckState state)
    {
        checkBox->setCheckState(state);
    }

private:
    QCheckBox* checkBox;
    QLineEdit* lineBox;
    QComboBox* comboBox;
};

#endif // EDITORWIDGET_H
