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
    ~MainWindow(); // vraag 32: destructor to clean up dynamic memory

private slots:
    void drawCircle();
    void drawRectangle();

private:
    QLabel* label;

    void drawShape(oop::Shape* s);

    // vraag 32: dynamic memory allocation (new)
    oop::Shape* dynamicShape;
};

#endif // MAINWINDOW_H
