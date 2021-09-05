#ifndef STAR_H
#define STAR_H

#include "object.h"

class Star : public Object
{
    Q_OBJECT
    Q_PROPERTY(int size READ getSize WRITE setSize)
private:
    int size;
public:
    Star();

    void setSize(int size);
    int getSize() const;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR_H
