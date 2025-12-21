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

private slots:
    void drawCircle();
    void drawRectangle();

private:
    QLabel* label;

    void drawShape(oop::Shape* s);

    // vraag 27: usage of namespace-qualified types
    oop::Circle circle;
    oop::Rectangle rect;
};

#endif // MAINWINDOW_H
