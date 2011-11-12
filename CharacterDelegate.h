/* 
 * File:   CharacterDelegate.h
 * Author: Quentin
 *
 * Created on 12 novembre 2011, 13:35
 */

#ifndef CHARACTERDELEGATE_H
#define	CHARACTERDELEGATE_H

class CharacterDelegate : public QStyledItemDelegate {
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
        QStyleOptionViewItemV4 opt = option;
        initStyleOption(&opt, index);

        QString line0 = index.model()->data(index.model()->index(index.row(), 1)).toString();
        QString line1 = index.model()->data(index.model()->index(index.row(), 2)).toString();

        // draw correct background
        opt.text = "";
        QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();
        style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, opt.widget);

        QRect rect = opt.rect;
        QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
        if (cg == QPalette::Normal && !(opt.state & QStyle::State_Active))
            cg = QPalette::Inactive;

        // set pen color
        if (opt.state & QStyle::State_Selected)
            painter->setPen(opt.palette.color(cg, QPalette::HighlightedText));
        else
            painter->setPen(opt.palette.color(cg, QPalette::Text));

        // draw 2 lines of text
        painter->drawText(QRect(rect.left(), rect.top(), rect.width(), rect.height() / 2),
                opt.displayAlignment, line0);
        painter->drawText(QRect(rect.left(), rect.top() + rect.height() / 2, rect.width(), rect.height() / 2),
                opt.displayAlignment, line1);
    }

    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const {
        QSize result = QStyledItemDelegate::sizeHint(option, index);
        result.setHeight(result.height()*2);
        return result;
    }
};

#endif	/* CHARACTERDELEGATE_H */
