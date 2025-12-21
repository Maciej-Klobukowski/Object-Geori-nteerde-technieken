#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // vraag 30: const references for functions (return const reference)
    inline const oop::Circle& circleRef() const { return circle; }      // #3
    inline const oop::Rectangle& rectRef() const { return rect; }       // #4

private slots:
    void drawCircle();
    void drawRectangle();

private:
    QLabel* label;

    void drawShape(oop::Shape* s);

    oop::Circle circle;
    oop::Rectangle rect;
};

#endif // MAINWINDOW_H
