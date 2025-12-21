#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    dynamicShape(nullptr)
{
    setWindowTitle("OOP Qt Example");
    resize(320, 220);

    QPushButton* btnCircle = new QPushButton("Create Circle", this);
    btnCircle->setGeometry(20, 20, 130, 35);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Create Rectangle", this);
    btnRect->setGeometry(170, 20, 130, 35);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    QPushButton* btnClear = new QPushButton("Delete Shape", this);
    btnClear->setGeometry(20, 60, 130, 35);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::clearShape);

    /*
     * vraag 36: useful container class usage
     * Button dat alle shapes in de container tekent.
     */
    QPushButton* btnAll = new QPushButton("Draw All", this);
    btnAll->setGeometry(170, 60, 130, 35);
    connect(btnAll, &QPushButton::clicked, this, &MainWindow::drawAllShapes);

    label = new QLabel("Click a button...", this);
    label->setGeometry(20, 120, 280, 80);

    // vraag 36: container wordt gevuld met bestaande objects + (optioneel) dynamic
    shapeList.append(&circle);
    shapeList.append(&rect);
}

MainWindow::~MainWindow() {
    delete dynamicShape;
}

void MainWindow::drawShape(oop::Shape* s) {
    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

void MainWindow::clearShape() {
    delete dynamicShape;
    dynamicShape = nullptr;
    label->setText("Shape deleted");
}

void MainWindow::drawCircle() {
    clearShape();
    dynamicShape = new oop::Circle(25, "Dynamic Circle");

    // vraag 36: container houdt ook dynamic shape bij
    if (!shapeList.contains(dynamicShape)) {
        shapeList.append(dynamicShape);
    }

    drawShape(dynamicShape);
}

void MainWindow::drawRectangle() {
    clearShape();
    dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");

    if (!shapeList.contains(dynamicShape)) {
        shapeList.append(dynamicShape);
    }

    drawShape(dynamicShape);
}

/*
 * vraag 36: useful container class
 * Itereer over QVector om meerdere shapes polymorf te tekenen.
 */
void MainWindow::drawAllShapes() {
    QString out;
    for (oop::Shape* s : shapeList) {
        if (s != nullptr) {
            out += s->draw() + "\n";
        }
    }
    label->setText(out.trimmed());
}
