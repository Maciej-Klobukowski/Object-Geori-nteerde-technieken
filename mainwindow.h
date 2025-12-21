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
    ~MainWindow();

private slots:
    void drawCircle();
    void drawRectangle();

    // vraag 33: explicit dynamic memory removing
    void clearShape();

private:
    QLabel* label;

    void drawShape(oop::Shape* s);

    // vraag 32 + 33: dynamically allocated object
    oop::Shape* dynamicShape;
};

#endif // MAINWINDOW_H
