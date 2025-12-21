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

    // vraag 38: useful (modern) file-I/O
    void saveLogToFile();

private:
    QLabel* label = nullptr;

    void drawShape(oop::Shape* s);

    oop::Shape* dynamicShape = nullptr;
    QVector<oop::Shape*> shapeList;
};

#endif // MAINWINDOW_H
