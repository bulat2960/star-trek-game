#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include "player.h"

class Scene : public QGraphicsScene
{
private:
    Player* player;
public:
    Scene();

    void setPlayer(Player* player);

public slots:
    void keyPressEvent(QKeyEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // SCENE_H
