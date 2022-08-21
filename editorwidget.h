#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QPushButton>

class EditorWidget : public QWidget {
    Q_OBJECT
public:
    explicit EditorWidget(QWidget* parent = nullptr);

    void setPrice(const int& price);
    void setPosition(const int& position);
    int getPosition() const;
    void setSize(const double& size);
    double getSize() const;

private:
    QPushButton* pushButton;
    QLineEdit* lineEdit;
    QDoubleSpinBox* dSpinBox;
};

#endif // EDITORWIDGET_H
