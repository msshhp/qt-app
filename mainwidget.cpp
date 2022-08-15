#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    bool success = initDatabase();
    qDebug() << __PRETTY_FUNCTION__ << "initDatabase" << success;
    populateDataItem();

    connect(ui->deleteButton, SIGNAL(clicked(bool)), this, SLOT(remove()));
    connect(ui->addButton, &QPushButton::clicked, this, &MainWidget::add);
    connect(ui->submitButton, SIGNAL(clicked(bool)), this, SLOT(save()));
}

MainWidget::~MainWidget()
{
    closeDatabase();

    delete ui;
    delete model;
}

void MainWidget::populateDataItem()
{
    qDebug() << __PRETTY_FUNCTION__;

    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS books (isbn int not null primary key, title text, edition text, publisher text, copyright text, price text, authors text);");
    qDebug() << query.exec();
    qDebug() << query.lastError();
    qDebug() << db.tables();

    model = new QSqlTableModel(this, db);
    model->setTable("books");
    qDebug() << __PRETTY_FUNCTION__ << model->lastError();
    bool success = model->select();
    qDebug() << __PRETTY_FUNCTION__ << success << model->lastError();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, tr("ISBN"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Edition"));
    model->setHeaderData(3, Qt::Horizontal, tr("Publisher"));
    model->setHeaderData(4, Qt::Horizontal, tr("Copyright"));
    model->setHeaderData(5, Qt::Horizontal, tr("Price"));
    model->setHeaderData(6, Qt::Horizontal, tr("Authors"));

    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
}

void MainWidget::add()
{
    qDebug() << __PRETTY_FUNCTION__;

    int row = 0;
    model->insertRows(row, 1);
    model->setData(model->index(row, 0), ui->edIsbn->text());
    model->setData(model->index(row, 1), ui->edTitle->text());
    model->setData(model->index(row, 2), ui->edEdition->text());
    model->setData(model->index(row, 3), ui->edPublisher->text());
    model->setData(model->index(row, 4), ui->edCopyright->text());
    model->setData(model->index(row, 5), ui->dspinPrice->value());
    model->setData(model->index(row, 6), ui->edAuthors->text());
}

void MainWidget::remove()
{
    qDebug() << __PRETTY_FUNCTION__;

    int row = ui->tableView->currentIndex().row();
    if (QMessageBox::question(0, "Delete", "Record no. " + QString::number(row + 1) + " will be deleted. Are you sure?",
            QMessageBox::No, QMessageBox::Yes)
        == QMessageBox::Yes) {
        model->removeRow(row);
    }
}

void MainWidget::save()
{
    qDebug() << __PRETTY_FUNCTION__;

    bool success = model->submitAll();
    if (not success) {
        QMessageBox::critical(0, "Failed", "cannot save changes.");
    } else {
        QMessageBox::information(0, "success",
            "changes saved successfully.");
    }
    qDebug() << model->lastError();
}

bool MainWidget::initDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "MyLibrary");
    db.setHostName("localhost");
    db.setDatabaseName("MyDatabase");
    db.setUserName("user");
    db.setPassword("password");

    return db.open();
}

void MainWidget::closeDatabase() { db.close(); }
