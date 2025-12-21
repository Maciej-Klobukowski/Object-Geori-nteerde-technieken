#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void drawCircle();
    void drawRectangle();
    void clearShape();
    void drawAllShapes();

private:
    QLabel* label = nullptr; // vraag 37: nullptr for safe initialization

    void drawShape(oop::Shape* s);

    // vraag 37: pointer explicitly initialized to nullptr
    oop::Shape* dynamicShape = nullptr;

    QVector<oop::Shape*> shapeList;
};

#endif // MAINWINDOW_H
