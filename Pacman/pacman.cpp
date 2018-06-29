#include "pacman.h"
#include <QList>
#include <QGraphicsScene>

using namespace pconsts;

Pacman::Pacman(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}

Pacman::~Pacman()
{

}

void Pacman::moving(int x, int y, direction cur_dir)
{

    if(!this->isEnabled())
        return;

    direct = cur_dir;

    setPos(mapToParent(x, y));

    if (this->x() >= 200)
    {
        this->setX(200 - 20);
    }

    else if(this->x() <= 0)
    {
        this->setX(0);
    }

    if (this->y() >= 200)
    {
        this->setY(200 - 20);
    }

    else if (this->y() <= 0)
    {
        this->setY(0);
    }

    QRectF rect(this->x(), this->y(), 20, 20);
//    scene()->addRect(rect, QPen(Qt::red));

    QList<QGraphicsItem *> foundItem = scene()->items(rect);

    foreach (QGraphicsItem *item, foundItem) {
        if (item == this)
            continue;
        emit signalEatPoint(item);
    }

}

QRectF Pacman::boundingRect() const
{

    return QRectF(0, 0, 20, 20);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    QRectF rect(0, 0, 20, 20);

    painter->setBrush(Qt::yellow);

    if (direct == direction::RIGHT)
    {
        painter->drawPie(0, 0, 20, 20, -45 * 16, -270 * 16);
    }

    else if (direct == direction::LEFT)
    {
        painter->drawPie(0, 0, 20, 20, -135 * 16, 270 * 16);
    }

    else if (direct == direction::UP)
    {
        painter->drawPie(0, 0, 20, 20, 45 * 16, -270 * 16);
    }
    else
    {
       painter->drawPie(0, 0, 20, 20, -45 * 16, 270 * 16);
    }

//    painter->drawRect(rect);

}

