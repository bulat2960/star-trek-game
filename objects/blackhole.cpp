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
    image = image.scaled(starSize, starSize, Qt::IgnoreAspectRatio);
    image = image.convertToFormat(QImage::Format_ARGB32);

    for (int i = 0; i < starSize; i++)
    {
        for (int j = 0; j < starSize; j++)
        {
            QColor pixelColor = image.pixelColor(i, j);

            if (pixelColor.alpha() != 0)
            {
                int radius = starSize / 2;
                int dx = radius - i;
                int dy = radius - j;
                int distance = sqrt(dx * dx + dy * dy);

                if (distance <= radius)
                {
                    pixelColor.setAlpha(255 * (1 - distance * 1.0 / radius));
                }
                else
                {
                    pixelColor.setAlpha(0);
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
