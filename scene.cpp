#include "scene.h"

#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

Scene::Scene()
{

}

void Scene::setPlayer(Player *player)
{
    this->player = player;
    addItem(player);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if (key == Qt::Key_S)
    {
        player->stopPosAnimation();
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    player->calculateNextPosition(player->pos().toPoint(), event->scenePos().toPoint());
    player->runPosAnimation(player->pos().toPoint(), event->scenePos().toPoint());
}
