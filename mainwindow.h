#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"


/*
 * CLASS: MainWindow
 * This class uses composition to include UI elements and Shape objects.
 * It demonstrates correct object-oriented structuring of a UI controller class.
 */


class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

private:
    void drawShape(Shape* s); // helper for dynamic polymorphism

private slots:
    void drawCircle();
    void drawRectangle();

private:
    QLabel* label;

    //Vraag 8 useful and correct object composition

    /*
     * OBJECT COMPOSITION:
     * The window HAS-A Circle and Rectangle.
     * This is correct because a window is not a shape, but uses them.
     */

    Circle circle;
    Rectangle rect;
};

#endif // MAINWINDOW_H
