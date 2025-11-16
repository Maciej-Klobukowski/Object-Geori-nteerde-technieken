#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

<<<<<<< HEAD
=======
/*
 * CLASS: MainWindow
 * This class uses composition to include UI elements and Shape objects.
 * It demonstrates correct object-oriented structuring of a UI controller class.
 */
>>>>>>> 6a14b95 (Add MainWindow class header file)
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit MainWindow(QWidget *parent = nullptr);
=======
    MainWindow(QWidget *parent = nullptr);
>>>>>>> 6a14b95 (Add MainWindow class header file)

private slots:
    void drawCircle();
    void drawRectangle();

private:
    QLabel* label;
<<<<<<< HEAD
=======

    /*
     * OBJECT COMPOSITION:
     * The window HAS-A Circle and Rectangle.
     * This is correct because a window is not a shape, but uses them.
     */
>>>>>>> 6a14b95 (Add MainWindow class header file)
    Circle circle;
    Rectangle rect;
};

#endif // MAINWINDOW_H
