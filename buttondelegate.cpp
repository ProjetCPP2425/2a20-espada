#include "buttondelegate.h"
#include <QPushButton>
#include <QApplication>
#include <QMouseEvent>

ButtonDelegate::ButtonDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    deleteButton = new QPushButton("Supprimer");
    editButton = new QPushButton("Modifier");
}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 6 || index.column() == 7) {  // Updated column numbers
        QStyleOptionButton buttonOption;
        buttonOption.rect = option.rect.adjusted(5, 5, -5, -5);

        if (index.column() == 6) { // Column 6: Supprimer button
            buttonOption.text = "Supprimer";
        } else if (index.column() == 7) { // Column 7: Modifier button
            buttonOption.text = "Modifier";
        }

        QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (index.column() == 6) { // Supprimer button clicked
            emit deleteButtonClicked(index);
            return true;
        } else if (index.column() == 7) { // Modifier button clicked
            emit editButtonClicked(index);
            return true;
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
