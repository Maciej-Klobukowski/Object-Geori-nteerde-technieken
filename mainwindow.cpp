#include "mainwindow.h"

#include <QSaveFile>
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QTextStream>
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

    /*
     * vraag 40: useful usage of lambda function
     * Lambda wordt gebruikt als inline slot:
     * - kort
     * - lokaal
     * - geen extra member function nodig
     */
    QPushButton* btnInfo = new QPushButton("Show Info", this);
    connect(btnInfo, &QPushButton::clicked, this, [this]() {
        if (dynamicShape != nullptr) {
            label->setText(dynamicShape->describe());
        } else {
            label->setText("No dynamic shape available");
        }
    });

    label = new QLabel("Click a button...", this);

    shapeList.append(&circle);
    shapeList.append(&rect);
}

MainWindow::~MainWindow() {
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

