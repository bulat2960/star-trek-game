#include "quadrant.h"
#include "gamesettings.h"

#include <QPainter>

Quadrant::Quadrant()
{
    int quadrantSize = GameSettings::instance()->getQuadrantSize();
    image = QImage(":/images/star-background.png");
    image = image.scaled(quadrantSize, quadrantSize, Qt::IgnoreAspectRatio);
}

QRectF Quadrant::boundingRect() const
{
    int quadrantSize = GameSettings::instance()->getQuadrantSize();
    return QRectF(0, 0, quadrantSize, quadrantSize);
}

void Quadrant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->setOpacity(0.9);
    painter->drawImage(0, 0, image);
    painter->setOpacity(1);

    QPen bigPen(Qt::red, 5);

    painter->setOpacity(0.5);

    painter->setPen(bigPen);
    painter->drawRect(boundingRect());
}
