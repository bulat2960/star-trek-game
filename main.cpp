#include <QApplication>
#include <QScreen>

#include "view.h"
#include "scene.h"
#include "quadrant.h"
#include "gamesettings.h"
#include "mainwindow.h"
#include "gamecontroller.h"
#include "guicontroller.h"
#include "player.h"
#include "blackhole.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int quadrantSize = GameSettings::instance()->getQuadrantSize();

    QScreen* screen = a.screens().first();
    int screenHeight = screen->geometry().height();
    int screenWidth = screen->geometry().width();

    MainWindow* mainWindow = new MainWindow;
    mainWindow->setGeometry(0, 0, screenWidth, screenHeight);

    Scene* scene = new Scene;

    View* view = new View(scene);
    view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    view->setParent(mainWindow);
    view->setGeometry(mainWindow->geometry());

    scene->setParent(view);

    GuiController* guiController = new GuiController;
    guiController->setScene(scene);
    guiController->setView(view);
    guiController->setMainWindow(mainWindow);

    Galaxy* galaxy = new Galaxy;

    int galaxyHeight = GameSettings::instance()->getGalaxyHeight();
    int galaxyWidth = GameSettings::instance()->getGalaxyWidth();

    for (int i = 0; i < galaxyHeight; i++)
    {
        for (int j = 0; j < galaxyWidth; j++)
        {
            Quadrant* quadrant = new Quadrant;
            galaxy->setQuadrant(quadrant, j, i);
            quadrant->setPos(QPoint(i, j) * quadrantSize);
            scene->addItem(quadrant);
        }
    }

    Player* player = new Player;
    player->setPos(1000, 1000);
    scene->setPlayer(player);
    view->centerOn(player);

    Blackhole* blackhole = new Blackhole;
    blackhole->setPos(800, 800);
    scene->addItem(blackhole);

    QObject::connect(player, &Player::posChanged, view, &View::changeCenterOn);

    GameController* gameController = new GameController(galaxy);

    guiController->start();

    return a.exec();
}
