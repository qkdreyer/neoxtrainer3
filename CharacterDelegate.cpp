/* 
 * File:   DatabaseManager.cpp
 * Author: Quentin
 * 
 * Created on 12 novembre 2011, 15:05
 */

#include "CharacterDelegate.h"
#include <iostream>
CharacterDelegate::CharacterDelegate(QWidget* parent = 0) : QStyledItemDelegate(parent) {
}

void CharacterDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    // initialize drawing with Qt 4.4
    QStyleOptionViewItemV4 opt = option;
    initStyleOption(&opt, index);
    
    // remove standart displayed data
    opt.text = "";
    
    // draw correct background
    QStyle* style = opt.widget ? opt.widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, opt.widget);
    
    // set displayed data
    QString display = index.model()->data(index.model()->index(index.row(), 6)).toString() // name
            + " (" + index.model()->data(index.model()->index(index.row(), 4)).toString() // server
            + " " + index.model()->data(index.model()->index(index.row(), 5)).toString() // channel
            + ")";
    painter->drawText(opt.rect, opt.displayAlignment, display);
}
