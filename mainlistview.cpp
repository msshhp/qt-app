#include "mainlistview.h"
#include "delegate.h"
#include <QStandardItemModel>

MainListView::MainListView(QWidget* parent)
    : QListView(parent)
{

    auto* delegate = new Delegate(this);
    //    QPalette p(palette());

    //    p.setBrush(QPalette::WindowText, QColor("#303030"));
    //    p.setBrush(QPalette::Base, QColor("#F0F1F2"));
    //    p.setBrush(QPalette::Light, QColor("#FFFFFF"));
    //    p.setBrush(QPalette::Midlight, QColor("#D3D6D8"));
    //    p.setBrush(QPalette::Mid, QColor("#C5C9Cb"));
    //    p.setBrush(QPalette::Dark, QColor("#9AA0A4"));
    //    p.setBrush(QPalette::Text, QColor("#616b71"));
    //    p.setBrush(QPalette::Highlight, QColor("#E2E4E5"));

    //    delegate->setContentsMargins(8, 8, 8, 8);
    //    delegate->setIconSize(32, 32);
    //    delegate->setHorizontalSpacing(8);
    //    delegate->setVerticalSpacing(4);

    //    setPalette(p);
    //    setFont(QFont("MSShellDlg 2", 12));

    setItemDelegate(delegate);

    setModel(new QStandardItemModel(this));

    setFlow(QListView::Flow::LeftToRight);

    //    setEditTriggers(EditTrigger::AllEditTriggers);

    addItem(1770, 800, 50);
    addItem(1720, 800, 50);
    addItem(1970, 800, 53);
    addItem(1740, 600, 53);
    addItem(1770, 600, 53);
    addItem(1879, 650, 50);
    addItem(1734, 600, 50);
    addItem(1770, 600, 53);
    addItem(1879, 650, 50);
    addItem(1734, 600, 50);
    addItem(1770, 600, 53);
    addItem(1879, 650, 50);
    addItem(1734, 600, 50);
    addItem(1770, 600, 53);
    addItem(1879, 650, 50);
    addItem(1734, 600, 50);
    resize(640, 300);

    //    this->openPersistentEditor(this->model()->index(0, 0));
}

void MainListView::addItem(const int& price, const int& position, const int& size)
{
    auto* item = new QStandardItem(QString::number(price));

    item->setData(QString::number(position), Qt::UserRole + 1);
    item->setData(QString::number(size), Qt::UserRole + 2);
    item->setFlags(Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable);
    qDebug() << item->data() << item->data(Qt::UserRole + 2);

    static_cast<QStandardItemModel*>(model())->appendRow(item);
    scrollToBottom();
}

void MainListView::clearAll()
{
    static_cast<QStandardItemModel*>(model())->clear();
}
