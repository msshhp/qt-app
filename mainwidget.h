#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void populateDataItem();

public slots:
    void add();
    void remove();
    void save();

private:
    Ui::MainWidget *ui;

    QSqlTableModel *model;
    QSqlDatabase db;

    bool initDatabase();
    void closeDatabase();
};

#endif // MAINWIDGET_H
