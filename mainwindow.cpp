#include "mainwindow.h"
#include <QtConcurrent>
#include <QPushButton>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // vraag 47: GUI usage
    resize(400, 300);

    QPushButton* c = new QPushButton("Circle", this);
    QPushButton* r = new QPushButton("Rectangle", this);

    label = new QLabel("Ready", this);
    label->move(20, 200);

    // vraag 19: usage of this
    connect(c, &QPushButton::clicked, this, &MainWindow::drawCircle);
    connect(r, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    // vraag 40: lambda
    connect(this, &MainWindow::shapeChanged, this,
            [this](const QString& s) {
                label->setText(s);
            });

    // vraag 42: QTimer
    timer.setSingleShot(true);
}

MainWindow::~MainWindow() {
    delete dynamicShape; // vraag 33
}

void MainWindow::drawCircle() {
    clearShape();

    // vraag 32: new
    dynamicShape = new oop::Circle(20, "Dynamic Circle");

    // vraag 18
    oop::DrawingTool tool(dynamicShape);
    emit shapeChanged(tool.performDraw());
}

void MainWindow::drawRectangle() {
    clearShape();
    dynamicShape = new oop::Rectangle(30, 15, "Dynamic Rect");
    emit shapeChanged(dynamicShape->draw());
}

void MainWindow::clearShape() {
    if (dynamicShape != nullptr) { // vraag 37
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

void MainWindow::updateLabel(const QString& t) {
    label->setText(t);
}
