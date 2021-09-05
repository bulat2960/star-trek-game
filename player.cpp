#include "player.h"
#include "gamesettings.h"

#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsScene>

Player::Player()
{
    int rocketSize = GameSettings::instance()->getRocketSize();
    image = QImage(":/images/rocket.png");
    image = image.scaled(rocketSize * 2, rocketSize * 2, Qt::IgnoreAspectRatio);

    posAnimation->setDuration(1000);
    connect(posAnimation, &QPropertyAnimation::valueChanged, this, &Player::posChanged);

    destinationPoint = QPoint(0, 0);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    int graphicalSize = GameSettings::instance()->getRocketSize();

    QLineF line1(pos().toPoint(), pos().toPoint() + QPoint(0, -10));
    QLineF line2(pos().toPoint(), destinationPoint);
    qreal angle = line1.angleTo(line2);

    painter->save();
    painter->rotate(-angle);
    painter->drawImage(-graphicalSize, -graphicalSize, image);

    painter->restore();
}

QPoint Player::calculateNextPosition(QPoint startPosition, QPoint endPosition)
{
    Q_UNUSED(startPosition);

    destinationPoint = endPosition;

    return endPosition;
}
