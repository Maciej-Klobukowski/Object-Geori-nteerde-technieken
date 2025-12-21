#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QFutureWatcher>
#include <QTimer>   // vraag 42: useful Qt class

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
    void saveLogToFileAsync();

    // vraag 42: Qt class usage
    void clearStatusMessage();

private:
    QLabel* label = nullptr;

    void drawShape(oop::Shape* s);

    oop::Shape* dynamicShape = nullptr;
    QVector<oop::Shape*> shapeList;

    QFutureWatcher<bool> saveWatcher;

    // vraag 42: useful Qt class
    QTimer statusTimer;
};

#endif // MAINWINDOW_H
