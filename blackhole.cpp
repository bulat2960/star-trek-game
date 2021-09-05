#include "blackhole.h"
#include "gamesettings.h"

#include <QTimer>
#include <QPainter>

#include <cmath>
#include <QDebug>

Blackhole::Blackhole()
{
    int starSize = GameSettings::instance()->getStarSize();
    this->size = starSize;

    image = QImage(":/images/blackhole.png");
    image = image.scaled(starSize * 2, starSize * 2, Qt::IgnoreAspectRatio);

    for (int i = 0; i < starSize * 2; i++)
    {
        for (int j = 0; j < starSize * 2; j++)
        {
            QColor pixelColor = image.pixelColor(i, j);

            if (pixelColor.alpha() != 0)
            {
                int dx = starSize - i;
                int dy = starSize - j;
                int distance = sqrt(dx * dx + dy * dy);

                if (distance <= starSize + 1)
                {
                    pixelColor.setAlpha(255 * (1 - distance * 1.0 / starSize));
                }
            }
            image.setPixelColor(i, j, pixelColor);
        }
    }

    rotationAnimation->setDuration(10000);
    runRotationAnimation(0, 360);

    QTimer* timer = new QTimer(this);
    timer->setInterval(10000);
    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, [this] {
        runRotationAnimation(0, 360);
    });
    timer->start();

    QPropertyAnimation* sizeAnim = new QPropertyAnimation(this, "size");
    sizeAnim->setStartValue(size);
    sizeAnim->setEndValue(size * 2);
    sizeAnim->setDuration(1000);
    sizeAnim->start();
}

void Blackhole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(boundingRect(), image);
}
