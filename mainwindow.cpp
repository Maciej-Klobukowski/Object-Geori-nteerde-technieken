#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    circle(30, "Big Circle"),
    rect(40, 20, "Custom Rectangle")
{
    setWindowTitle("OOP Qt Example");
    resize(300, 200);

    QPushButton* btnCircle = new QPushButton("Draw Circle", this);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Draw Rectangle", this);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    label = new QLabel("Click a button...", this);
}

void MainWindow::drawShape(oop::Shape* s) {
    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

void MainWindow::drawCircle() {
    drawShape(&circle);
}

void MainWindow::drawRectangle() {
    drawShape(&rect);
}
