#ifndef QUADRANT_H
#define QUADRANT_H

#include <QVector>
#include <QGraphicsRectItem>

class Quadrant : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QImage image;
public:
    Quadrant();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // QUADRANT_H
