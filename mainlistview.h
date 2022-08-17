#ifndef MAINLISTVIEW_H
#define MAINLISTVIEW_H

#include <QListView>

class MainListView : public QListView {
    Q_OBJECT
public:
    explicit MainListView(QWidget* parent = nullptr);

public slots:
    void addItem(const int& price, const int& position, const int& size);
    void clearAll();
};

#endif // MAINLISTVIEW_H
