#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "galaxy.h"

class GameController : public QObject
{
    Q_OBJECT
private:
    Galaxy* galaxy;
public:
    GameController(Galaxy* galaxy);
};

#endif // GAMECONTROLLER_H
