#include "delegate.h"
#include "editorwidget.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QScreen>

Delegate::Delegate(QObject* parent)
    : QStyledItemDelegate(parent)
{

    btn = new QPushButton("...");
}

void Delegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyleOptionButton buttonOption;

    QRect r = option.rect; // getting the rect of the cell
    int x, y, w, h;
    x = r.left() + r.width() - 50; // the X coordinate
    y = r.top(); // the Y coordinate
    w = 50; // button width
    h = 30; // button height
    buttonOption.rect = QRect(x, y, w, h);
    buttonOption.state = QStyle::State_Enabled;
    buttonOption.text = index.data(Qt::DisplayRole).toString();
    //    buttonOption.rect = option.rect.adjusted(1, 1, -1, -1);
    QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);

    //    btn->setGeometry(QRect(x, y + 90, w, h));
    //    btn->setText("TEST");

    //    QPixmap map = btn->grab();
    //    painter->drawPixmap(option.rect.x(), option.rect.y(), map);

    //    QPushButton detail(index.data().toString());
    //    detail.setGeometry(option.rect);
    //    detail.setText("Detail");
    //    painter->save();
    //    painter->translate(option.rect.topLeft());
    //    detail.render(painter);
    //    painter->restore();

    QStyleOptionButton buttonOption1;
    buttonOption1.rect = QRect(x, y + 50, w, h);
    buttonOption1.state = QStyle::State_Enabled;

    buttonOption1.text = index.data(Qt::UserRole + 1).toString();
    QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption1, painter);

    QStyleOptionButton buttonOption2;
    buttonOption2.rect = QRect(x, y + 100, w, h);
    buttonOption2.state = QStyle::State_Enabled;

    buttonOption2.text = index.data(Qt::UserRole + 2).toString();
    QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption2, painter);

    qDebug() << index.data(Qt::UserRole + 1) << index.data(Qt::UserRole + 2);
    //    QStyledItemDelegate::paint(painter, option, index);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem& option,
    const QModelIndex& index) const
{
    QSize s(60, 200); // test hard coded
    return s.isValid() ? s : QStyledItemDelegate::sizeHint(option, index);
}

QWidget* Delegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    //    Q_UNUSED(option)
    //    Q_UNUSED(index)
    //    EditorWidget* editor = new EditorWidget(parent);
    //    return editor;
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void Delegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    //    EditorWidget* widget = static_cast<EditorWidget*>(editor);
    //    widget->blockSignals(true);
    //    widget->setText(index.data(Qt::DisplayRole).toString());
    //    Qt::CheckState state = static_cast<Qt::CheckState>(index.data(Qt::CheckStateRole).toInt());
    //    widget->setCheckState(state);
    //    widget->setCurrentIndex(index.data(Qt::UserRole).toInt());
    //    widget->blockSignals(false);
    QStyledItemDelegate::setEditorData(editor, index);
}
