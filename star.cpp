#include "star.h"

#include <QPainter>

Star::Star()
{

}

void Star::setSize(int size)
{
    this->size = size;
}

int Star::getSize() const
{
    return size;
}

QPainterPath Star::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(boundingRect(), image);
}
