#include "gamesettings.h"

GameSettings* GameSettings::gameSettings = nullptr;

GameSettings::GameSettings()
{
    settings = new QSettings("D:\\Dev\\C++\\Qt\\Active Projects\\StarTrekGame\\settings.ini", QSettings::IniFormat);

    settings->beginGroup("GUI");
    settings->setValue("RocketSize", 30);
    settings->setValue("StarSize", 500);
    settings->endGroup();

    settings->beginGroup("Galaxy");
    settings->setValue("QuadrantsHeight", 10);
    settings->setValue("QuadrantsWidth", 10);
    settings->endGroup();

    settings->beginGroup("Quadrant");
    settings->setValue("Size", 500);
    settings->endGroup();

    settings->sync();
}

GameSettings* GameSettings::instance()
{
    if (not gameSettings)
    {
        gameSettings = new GameSettings;
    }

    return gameSettings;
}

int GameSettings::getRocketSize() const
{
    return settings->value("GUI/RocketSize", 30).toInt();
}

int GameSettings::getStarSize() const
{
    return settings->value("GUI/StarSize", 500).toInt();
}

int GameSettings::getGalaxyHeight() const
{
    return settings->value("Galaxy/QuadrantsHeight", 10).toInt();
}

int GameSettings::getGalaxyWidth() const
{
    return settings->value("Galaxy/QuadrantsWidth", 10).toInt();
}

int GameSettings::getQuadrantSize() const
{
    return settings->value("Quadrant/Size", 10).toInt();
}

GameSettings::~GameSettings()
{
    settings->sync();
    settings->deleteLater();
}
