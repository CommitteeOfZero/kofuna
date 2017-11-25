#include "flatcheckbox.h"
#include <QStyle>
#include <QStylePainter>
#include <QStyleOptionButton>
#include <QStyleOptionFocusRect>

FlatCheckBox::FlatCheckBox(QWidget *parent) : QCheckBox(parent) {}

FlatCheckBox::~FlatCheckBox() {}

void FlatCheckBox::paintEvent(QPaintEvent *ev) {
    QStylePainter paint(this);
    QStyleOptionButton opt;
    initStyleOption(&opt);

    opt.rect =
        style()->subElementRect(QStyle::SE_CheckBoxIndicator, &opt, this);
    paint.setPen(opt.palette.text().color());
    paint.drawRect(opt.rect);

    if (!(opt.state & QStyle::State_Off)) {
        QLineF lines[7];
        int i, xx, yy;
        xx = opt.rect.x() + 4;
        yy = opt.rect.y() + 6;
        for (i = 0; i < 3; ++i) {
            lines[i] = QLineF(xx, yy, xx, yy + 2);
            ++xx;
            ++yy;
        }
        yy -= 2;
        for (i = 3; i < 7; ++i) {
            lines[i] = QLineF(xx, yy, xx, yy + 2);
            ++xx;
            --yy;
        }
        paint.drawLines(lines, 7);
    }

    initStyleOption(&opt);
    opt.rect = style()->subElementRect(QStyle::SE_CheckBoxContents, &opt, this);
    paint.drawControl(QStyle::CE_CheckBoxLabel, opt);

    initStyleOption(&opt);
    if (opt.state & QStyle::State_HasFocus) {
        QStyleOptionFocusRect fropt;
        fropt.QStyleOption::operator=(opt);
        fropt.rect =
            style()->subElementRect(QStyle::SE_CheckBoxFocusRect, &opt, this);
        style()->drawPrimitive(QStyle::PE_FrameFocusRect, &fropt, &paint, this);
    }
}
