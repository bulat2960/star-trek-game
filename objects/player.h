#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsObject>
#include <QPropertyAnimation>

#include "object.h"

class Player : public Object
{
    Q_OBJECT
private:
    QPoint destinationPoint;
public:
    Player();

    QPoint calculateNextPosition(QPoint startPosition, QPoint endPosition);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void posChanged(const QVariant& value);
};

#endif // PLAYER_H
