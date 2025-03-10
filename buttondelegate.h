#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QStyledItemDelegate>
#include <QPushButton>

class ButtonDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ButtonDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

signals:
    void deleteButtonClicked(const QModelIndex &index);
    void editButtonClicked(const QModelIndex &index);

private:
    QPushButton *deleteButton;
    QPushButton *editButton;
};

#endif // BUTTONDELEGATE_H
