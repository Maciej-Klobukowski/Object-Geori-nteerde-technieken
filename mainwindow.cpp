#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    dynamicShape(nullptr)
{
    setWindowTitle("OOP Qt Example");
    resize(300, 200);

    QPushButton* btnCircle = new QPushButton("Create Circle", this);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Create Rectangle", this);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    QPushButton* btnClear = new QPushButton("Delete Shape", this);
    btnClear->setGeometry(20, 60, 120, 40);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::clearShape);

    label = new QLabel("Click a button...", this);
}

/*
 * vraag 33: dynamic memory removing (delete)
 * Destructor verwijdert eventueel nog bestaand object.
 */
MainWindow::~MainWindow() {
    delete dynamicShape;
}

/*
 * vraag 33: explicit delete usage
 * Verwijdert dynamisch object op vraag van gebruiker.
 */
void MainWindow::clearShape() {
    delete dynamicShape;     // <-- expliciete delete
    dynamicShape = nullptr;  // voorkom dangling pointer
    label->setText("Shape deleted");
}

void MainWindow::drawShape(oop::Shape* s) {
    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

void MainWindow::drawCircle() {
    clearShape(); // eerst oude verwijderen
    dynamicShape = new oop::Circle(25, "Dynamic Circle");
    drawShape(dynamicShape);
}

void MainWindow::drawRectangle() {
    clearShape(); // eerst oude verwijderen
    dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");
    drawShape(dynamicShape);
}
