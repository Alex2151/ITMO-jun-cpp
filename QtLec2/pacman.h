#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>


class Pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pacman(QObject *parent = 0);
    ~Pacman();

    void moving(int x, int y);

protected:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PACMAN_H
