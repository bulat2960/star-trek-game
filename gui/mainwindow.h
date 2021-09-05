#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QKeyEvent>

#include "view.h"

class MainWindow : public QWidget
{
private:
    View* view;
public:
    MainWindow();

public slots:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // MAINWINDOW_H
