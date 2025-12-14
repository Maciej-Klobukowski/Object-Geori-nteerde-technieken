#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     // Uses the parameterized constructors
    circle(30, "Big Circle"),
    rect(40, 20, "Custom Rectangle")
{
    setWindowTitle("OOP Qt Example");
    resize(300, 200);

    QPushButton* btnCircle = new QPushButton("Draw Circle", this);
    btnCircle->setGeometry(20, 20, 120, 40);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Draw Rectangle", this);
    btnRect->setGeometry(150, 20, 120, 40);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    label = new QLabel("Click a button...", this);
    label->setGeometry(20, 100, 260, 40);
}

// New helper function demonstrating useful dynamic polymorphism
void MainWindow::drawShape(Shape* s) {
    // Dynamic polymorphism: the correct draw() is called at runtime
    DrawingTool tool(s);
    this->label->setText(s->draw());
}


void MainWindow::drawCircle() {
    /*
     * vraag 7 useful and correct polymorphism + vraag 8 useful and correct object composition
     *
     * COMPOSITION + POLYMORPHISM:
     * DrawingTool uses a Shape* (Circle here).
     * draw() calls the correct overridden version at runtime.
     */
    DrawingTool tool(&circle);
    label->setText(tool.performDraw());
}

void MainWindow::drawRectangle() {
    DrawingTool tool(&rect);
    label->setText(tool.performDraw());
}
