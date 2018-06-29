#include "point.h"

Point::Point(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}

QRectF Point::boundingRect() const
{
    return QRectF(0, 0, 20, 20);
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::white);
    painter->drawEllipse(5, 5, 10, 10);
//    painter->drawEllipse(QPoint(0, 0), 10, 10);
}


