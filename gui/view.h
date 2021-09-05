#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QTimeLine>

#include "scene.h"

class View : public QGraphicsView
{
private:
    Scene* scene;

    int numScheduledScalings;
    QTimeLine* scaleAnimationTimeLine {nullptr};

    void processScaling();
public:
    View(Scene* scene);

public slots:
    void changeCenterOn(const QVariant& value);
    void wheelEvent(QWheelEvent* event) override;
};

#endif // VIEW_H
