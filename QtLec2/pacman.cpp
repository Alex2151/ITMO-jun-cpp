#include "pacman.h"

#include <iostream>

Pacman::Pacman(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
//    angle = 0;
//    setRotation(angle);

}

Pacman::~Pacman(){}

void Pacman::moving(int x, int y)
{
    if (this->isEnabled())
        setPos(mapToParent(x, y));
}

QRectF Pacman::boundingRect() const
{
    return QRectF(0,0, 100, 100);
}


void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(40,0) << QPoint(40,40) << QPoint(0, 40);
    painter->setBrush(Qt::red);     /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  /// Рисуем полигон
    Q_UNUSED(option);
    Q_UNUSED(widget);

}



//    /* Проверка выхода за границы поля
//     * Если объект выходит за заданные границы, то возвращаем его назад
//     * */
//    if(this->x() - 10 < -250){
//        this->setX(-240);       // слева
//    }
//    if(this->x() + 10 > 250){
//        this->setX(240);        // справа
//    }

//    if(this->y() - 10 < -250){
//        this->setY(-240);       // сверху
//    }
//    if(this->y() + 10 > 250){
//        this->setY(240);        // снизу
//    }

