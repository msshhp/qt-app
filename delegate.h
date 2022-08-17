#ifndef DELEGATE_H
#define DELEGATE_H

#include <QPushButton>
#include <QStyledItemDelegate>

class Delegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit Delegate(QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
    void setEditorData(QWidget* editor, const QModelIndex& index) const override;
    //    void setModelData(QWidget *editor, QAbstractItemModel *model,
    //                      const QModelIndex &index) const override;

    QPushButton* btn;
};

#endif // DELEGATE_H
