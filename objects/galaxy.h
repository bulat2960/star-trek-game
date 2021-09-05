#ifndef GALAXY_H
#define GALAXY_H

#include <QVector>
#include "quadrant.h"

class Galaxy
{
private:
    QVector<QVector<Quadrant*>> matrix;

    int height;
    int width;
    int quadrantSize;
public:
    Galaxy();

    int getHeight() const;
    int getWidth() const;
    int getQuadrantSize() const;

    void setQuadrant(Quadrant* quadrant, int x, int y);
    Quadrant* getQuadrant(int x, int y) const;
};

#endif // GALAXY_H
