#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsObject>
#include <QPropertyAnimation>

class Object : public QGraphicsObject
{
    Q_OBJECT
protected:
    double mass;

    QPropertyAnimation* posAnimation {nullptr};
    QPropertyAnimation* rotationAnimation {nullptr};

    QImage image;

public:
    Object();

    void setMass(double mass);
    double getMass() const;

    virtual QRectF boundingRect() const override;

    void runPosAnimation(QPoint start, QPoint end);
    void stopPosAnimation();

    void runRotationAnimation(qreal startAngle, qreal rotationAngle);
    void stopRotationAnimation();
};

#endif // OBJECT_H
