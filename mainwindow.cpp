#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    dynamicShape(nullptr)
{
    setWindowTitle("OOP Qt Example");
    resize(300, 200);

    QPushButton* btnCircle = new QPushButton("Draw Circle (dynamic)", this);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Draw Rectangle (dynamic)", this);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    label = new QLabel("Click a button...", this);
}

/*
 * vraag 32: correct cleanup of dynamic memory
 */
MainWindow::~MainWindow() {
    delete dynamicShape;
}

void MainWindow::drawShape(oop::Shape* s) {
    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

/*
 * vraag 32: dynamic memory allocation using new
 * runtime beslist welk object wordt aangemaakt
 */
void MainWindow::drawCircle() {
    delete dynamicShape; // voorkom memory leak
    dynamicShape = new oop::Circle(25, "Dynamic Circle");
    drawShape(dynamicShape);
}

void MainWindow::drawRectangle() {
    delete dynamicShape; // voorkom memory leak
    dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");
    drawShape(dynamicShape);
}
