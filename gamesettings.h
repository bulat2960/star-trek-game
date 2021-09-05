#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <QSettings>

class GameSettings
{
private:
    static GameSettings* gameSettings;
    GameSettings();

    QSettings* settings {nullptr};
public:
    GameSettings(const GameSettings& settings) = delete;
    GameSettings& operator=(const GameSettings& settings) = delete;
    ~GameSettings();

    static GameSettings* instance();

    int getRocketSize() const;
    int getStarSize() const;
    int getGalaxyHeight() const;
    int getGalaxyWidth() const;
    int getQuadrantSize() const;
};

#endif // GAMESETTINGS_H
