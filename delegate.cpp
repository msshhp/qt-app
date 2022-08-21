#include "delegate.h"
#include "mainlistview.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QScreen>

Delegate::Delegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
    qDebug() << __FUNCTION__ << parent << parent->objectName() << this << this->objectName();

    if (auto listView = qobject_cast<MainListView*>(parent)) {
        editorWidget = new EditorWidget(listView);
        editorWidget->hide();
    }
}

void Delegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editorWidget->setGeometry(option.rect);
    editorWidget->setPrice(index.data().toInt());
    editorWidget->setPosition(index.data(Qt::UserRole + 1).toInt());
    editorWidget->setSize(index.data(Qt::UserRole + 2).toDouble());
    auto pixmap = editorWidget->grab();
    painter->drawPixmap(option.rect.x(), option.rect.y(), pixmap);

    //    qDebug() << index.data(Qt::UserRole + 1) << index.data(Qt::UserRole + 2);
    //    QStyledItemDelegate::paint(painter, option, index);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    //    qDebug() << __FUNCTION__ << option.rect;

    QSize s(80, 150); // test hard coded
    return s.isValid() ? s : QStyledItemDelegate::sizeHint(option, index);
}

QWidget* Delegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    qDebug() << __FUNCTION__ << parent;

    auto editor = new EditorWidget(parent);
    //    editor->setPrice(index.data().toInt());
    //    editor->setPosition(index.data(Qt::UserRole + 1).toInt());
    //    editor->setSize(index.data(Qt::UserRole + 2).toDouble());
    return editor;

    //    return QStyledItemDelegate::createEditor(parent, option, index);
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
    qDebug() << __FUNCTION__ << editor << index.data();

    if (auto widget = qobject_cast<EditorWidget*>(editor)) {
        qDebug() << __FUNCTION__ << "qobject_cast OK" << widget << index.data(Qt::UserRole + 1) << index.data(Qt::UserRole + 2);
        widget->setPrice(index.data().toInt());
        widget->setPosition(index.data(Qt::UserRole + 1).toInt());
        widget->setSize(index.data(Qt::UserRole + 2).toDouble());
        qDebug() << __FUNCTION__ << "qobject_cast OK" << widget->getPosition() << widget->getSize();
    } else {
        qDebug() << __FUNCTION__ << "qobject_cast FAILED";
    }

    //    QStyledItemDelegate::setEditorData(editor, index);
}

void Delegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    qDebug() << __FUNCTION__ << editor << model;

    if (auto widget = qobject_cast<EditorWidget*>(editor)) {
        qDebug() << __FUNCTION__ << "qobject_cast OK" << widget << widget->getPosition() << widget->getSize() << model;
        model->blockSignals(true);
        model->setData(index, widget->getPosition(), Qt::UserRole + 1);
        model->blockSignals(false);
        model->setData(index, widget->getSize(), Qt::UserRole + 2);
        qDebug() << __FUNCTION__ << "qobject_cast OK11111111" << widget << widget->getPosition() << widget->getSize() << model << model->data(index, Qt::UserRole + 1) << model->data(index, Qt::UserRole + 2);
    } else {
        qDebug() << __FUNCTION__ << "qobject_cast FAILED";
    }

    //    QStyledItemDelegate::setModelData(editor, model, index);
}

bool Delegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
    //    qDebug() << __FUNCTION__ << event << event->type() << index.data();
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
