#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector> // vraag 36: useful container class

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

    // vraag 36: use container class (iterate over multiple shapes)
    void drawAllShapes();

private:
    QLabel* label;

    void drawShape(oop::Shape* s);

    oop::Shape* dynamicShape;

    /*
     * vraag 36: useful container class
     * QVector<oop::Shape*> houdt meerdere shapes bij om erover te itereren.
     * Dit is nuttig om "Draw All" te kunnen doen.
     */
    QVector<oop::Shape*> shapeList;
};

#endif // MAINWINDOW_H
