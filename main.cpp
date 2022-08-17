#include "mainlistview.h"
#include "mainwidget.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWidget widget;
    MainListView list;

    //    w.show();
    //    widget.show();
    list.show();

    return a.exec();
}
