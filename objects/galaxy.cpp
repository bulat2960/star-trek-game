#include "galaxy.h"
#include "gamesettings.h"

Galaxy::Galaxy()
{
    height = GameSettings::instance()->getGalaxyHeight();
    width = GameSettings::instance()->getGalaxyWidth();
    quadrantSize = GameSettings::instance()->getQuadrantSize();

    matrix = QVector<QVector<Quadrant*>>(height, QVector<Quadrant*>(width, nullptr));
}

void Galaxy::setQuadrant(Quadrant* quadrant, int x, int y)
{
    matrix[y][x] = quadrant;
}

int Galaxy::getQuadrantSize() const
{
    return quadrantSize;
}

int Galaxy::getHeight() const
{
    return height;
}

int Galaxy::getWidth() const
{
    return width;
}

Quadrant* Galaxy::getQuadrant(int x, int y) const
{
    return matrix[y][x];
}
