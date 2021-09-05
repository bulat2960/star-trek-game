#include "guicontroller.h"

#include <QDebug>

GuiController::GuiController()
{
}

void GuiController::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

void GuiController::setScene(Scene *scene)
{
    this->scene = scene;
}

void GuiController::setView(View *view)
{
    this->view = view;
}

void GuiController::start()
{
    mainWindow->showFullScreen();
}
