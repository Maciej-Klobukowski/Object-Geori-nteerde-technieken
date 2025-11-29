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
    Circle circle;
    Rectangle rect;
};

#endif // MAINWINDOW_H
