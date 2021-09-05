#include "object.h"

Object::Object()
{
    posAnimation = new QPropertyAnimation(this, "pos");
    rotationAnimation = new QPropertyAnimation(this, "rotation");
}

QRectF Object::boundingRect() const
{
    int height = image.height();
    int width = image.width();
    return QRectF(-height / 2, -width / 2, height, width);
}

void Object::runPosAnimation(QPoint start, QPoint end)
{
    stopPosAnimation();
    posAnimation->setStartValue(start);
    posAnimation->setEndValue(end);
    posAnimation->start();
}

void Object::stopPosAnimation()
{
    if (posAnimation->state() == QPropertyAnimation::Running)
    {
        posAnimation->stop();
    }
}

void Object::runRotationAnimation(qreal startAngle, qreal rotationAngle)
{
    stopRotationAnimation();
    rotationAnimation->setStartValue(startAngle);
    rotationAnimation->setEndValue(rotationAngle);
    rotationAnimation->start();
}

void Object::stopRotationAnimation()
{
    if (rotationAnimation->state() == QPropertyAnimation::Running)
    {
        rotationAnimation->stop();
    }
}

