/* 
 * File:   CharacterDelegate.h
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 13:35
 */

#ifndef CHARACTERDELEGATE_H
#define CHARACTERDELEGATE_H
#include <QStyledItemDelegate>

class CharacterDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    CharacterDelegate(QWidget*);
protected:
    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const;
    QSize sizeHint(const QStyleOptionViewItem&, const QModelIndex&) const;
};

#endif	/* CHARACTERDELEGATE_H */
