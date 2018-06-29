#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include "pconsts.h"


class Pacman : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pacman(QObject *parent = 0);
    ~Pacman();

    void moving(int x, int y, pconsts::direction cur_dir);

signals:
    void signalEatPoint(QGraphicsItem *point);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    pconsts::direction direct = pconsts::direction::RIGHT;

};

#endif // PACMAN_H
