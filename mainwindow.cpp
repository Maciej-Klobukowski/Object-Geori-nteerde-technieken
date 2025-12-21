#include "mainwindow.h"

#include <QSaveFile>
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QTextStream>
#include <QtConcurrent/QtConcurrentRun>
#include <stdexcept>
#include <new>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("OOP Qt Example");
    resize(360, 240);

    QPushButton* btnCircle = new QPushButton("Create Circle", this);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Create Rectangle", this);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    QPushButton* btnClear = new QPushButton("Delete Shape", this);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::clearShape);

    QPushButton* btnAll = new QPushButton("Draw All", this);
    connect(btnAll, &QPushButton::clicked, this, &MainWindow::drawAllShapes);

    QPushButton* btnSaveAsync = new QPushButton("Save Log (Async)", this);
    connect(btnSaveAsync, &QPushButton::clicked, this, &MainWindow::saveLogToFileAsync);

    label = new QLabel("Click a button...", this);

    shapeList.append(&circle);
    shapeList.append(&rect);

    /*
     * vraag 43: useful signal/slot connection
     * UI wordt automatisch geüpdatet wanneer shapeChanged wordt uitgezonden.
     */
    connect(this, &MainWindow::shapeChanged,
            this, &MainWindow::updateStatusLabel);

    statusTimer.setSingleShot(true);
    statusTimer.setInterval(3000);
    connect(&statusTimer, &QTimer::timeout,
            this, &MainWindow::clearStatusMessage);
}

MainWindow::~MainWindow() {
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

void MainWindow::drawShape(oop::Shape* s) {
    if (s == nullptr) {
        emit shapeChanged("No shape to draw");
        return;
    }

    oop::DrawingTool tool(s);
    emit shapeChanged(tool.performDraw());
}

void MainWindow::drawCircle() {
    clearShape();
    try {
        dynamicShape = new oop::Circle(25, "Dynamic Circle");
        drawShape(dynamicShape);
    } catch (const std::bad_alloc&) {
        emit shapeChanged("Out of memory while creating Circle");
    }
}

void MainWindow::drawRectangle() {
    clearShape();
    try {
        dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");
        drawShape(dynamicShape);
    } catch (const std::bad_alloc&) {
        emit shapeChanged("Out of memory while creating Rectangle");
    }
}

void MainWindow::clearShape() {
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
        emit shapeChanged("Shape deleted");
    }
}

void MainWindow::drawAllShapes() {
    QString out;
    for (oop::Shape* s : shapeList) {
        if (s != nullptr) {
            out += s->draw() + "\n";
        }
    }
    emit shapeChanged(out.trimmed());
}

/*
 * vraag 43: slot implementation
 * Ontvangt signal en update UI.
 */
void MainWindow::updateStatusLabel(const QString& text) {
    label->setText(text);
    statusTimer.start();
}

void MainWindow::clearStatusMessage() {
    label->clear();
}

