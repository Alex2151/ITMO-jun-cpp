#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <QtWidgets>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class Point : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Point(QObject *parent = 0);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};



#endif // POINT_H
