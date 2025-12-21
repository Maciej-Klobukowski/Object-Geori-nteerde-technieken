#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("OOP Qt Example");
    resize(320, 220);

    QPushButton* btnCircle = new QPushButton("Create Circle", this);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Create Rectangle", this);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    QPushButton* btnClear = new QPushButton("Delete Shape", this);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::clearShape);

    QPushButton* btnAll = new QPushButton("Draw All", this);
    connect(btnAll, &QPushButton::clicked, this, &MainWindow::drawAllShapes);

    label = new QLabel("Click a button...", this);

    shapeList.append(&circle);
    shapeList.append(&rect);
}

MainWindow::~MainWindow() {
    // vraag 37: safe delete guarded by nullptr check
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

void MainWindow::drawShape(oop::Shape* s) {
    // vraag 37: nullptr check before usage
    if (s == nullptr) {
        label->setText("No shape to draw");
        return;
    }

    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

void MainWindow::clearShape() {
    // vraag 37: nullptr used to check ownership before delete
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
        label->setText("Shape deleted");
    } else {
        label->setText("No shape to delete");
    }
}

void MainWindow::drawCircle() {
    clearShape();
    dynamicShape = new oop::Circle(25, "Dynamic Circle");
    drawShape(dynamicShape);
}

void MainWindow::drawRectangle() {
    clearShape();
    dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");
    drawShape(dynamicShape);
}

void MainWindow::drawAllShapes() {
    QString out;
    for (oop::Shape* s : shapeList) {
        if (s != nullptr) { // vraag 37: nullptr guard in container iteration
            out += s->draw() + "\n";
        }
    }
    label->setText(out.trimmed());
}
