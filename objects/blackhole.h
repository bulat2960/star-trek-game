#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "star.h"

class Blackhole : public Star
{
    Q_OBJECT
    Q_PROPERTY(int size READ getSize WRITE setSize)
public:
    Blackhole();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    int size;
};

#endif // BLACKHOLE_H
