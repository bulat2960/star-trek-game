#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QGraphicsItem>

#include "view.h"
#include "scene.h"
#include "mainwindow.h"

class GuiController : public QObject
{
    Q_OBJECT
private:
    MainWindow* mainWindow;
    Scene* scene;
    View* view;
public:
    GuiController();

    void setMainWindow(MainWindow* mainWindow);
    void setScene(Scene* scene);
    void setView(View* view);

    void start();
};

#endif // GUICONTROLLER_H
