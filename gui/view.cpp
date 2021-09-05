#include "view.h"

#include <QDebug>
#include <QMouseEvent>

#include <QtMath>

View::View(Scene* scene)
{
    this->scene = scene;
    setScene(scene);

    centerOn(0, 0);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFrameStyle(0);

    // Оставить для маски
    //setMask(QRegion(QRect(100, 100, 200, 200)));

    scaleAnimationTimeLine = new QTimeLine(400, this);
    scaleAnimationTimeLine->setUpdateInterval(20);
    connect(scaleAnimationTimeLine, &QTimeLine::valueChanged, this, &View::processScaling);
}

void View::changeCenterOn(const QVariant& value)
{
    if (value.type() == QVariant::Invalid)
    {
        return;
    }

    clearMask();
    QPointF scenePoint = value.toPointF();

    centerOn(value.toPointF());
    scene->invalidate(scenePoint.x() - 350, scenePoint.y() - 350, 700, 700);

    // Оставить для маски
    //QPointF viewPoint = mapFromScene(scenePoint);
    //setMask(QRegion(viewPoint.x() - 350, viewPoint.y() - 350, 700, 700, QRegion::Ellipse));
}

void View::wheelEvent(QWheelEvent *event)
{
    if (scaleAnimationTimeLine->state() == QTimeLine::Running)
    {
        scaleAnimationTimeLine->stop();
    }

    int numDegrees = event->angleDelta().y() / 8;
    int numSteps = numDegrees / 15;

    if (numScheduledScalings * numSteps < 0)
    {
        numScheduledScalings = numSteps;
    }

    scaleAnimationTimeLine->start();
}

void View::processScaling()
{
    qreal factor = 1.0 + qreal(numScheduledScalings) / 200.0;
    scale(factor, factor);
}
