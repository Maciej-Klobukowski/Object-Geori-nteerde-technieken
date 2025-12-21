#include "mainwindow.h"

#include <QSaveFile>         // vraag 38: modern/atomic file-I/O
#include <QStandardPaths>    // vraag 38: portable save location
#include <QDir>
#include <QDateTime>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("OOP Qt Example");
    resize(360, 240);

    QPushButton* btnCircle = new QPushButton("Create Circle", this);
    btnCircle->setGeometry(20, 20, 150, 35);
    connect(btnCircle, &QPushButton::clicked, this, &MainWindow::drawCircle);

    QPushButton* btnRect = new QPushButton("Create Rectangle", this);
    btnRect->setGeometry(190, 20, 150, 35);
    connect(btnRect, &QPushButton::clicked, this, &MainWindow::drawRectangle);

    QPushButton* btnClear = new QPushButton("Delete Shape", this);
    btnClear->setGeometry(20, 60, 150, 35);
    connect(btnClear, &QPushButton::clicked, this, &MainWindow::clearShape);

    QPushButton* btnAll = new QPushButton("Draw All", this);
    btnAll->setGeometry(190, 60, 150, 35);
    connect(btnAll, &QPushButton::clicked, this, &MainWindow::drawAllShapes);

    // vraag 38: useful (modern) file-I/O trigger vanuit UI
    QPushButton* btnSave = new QPushButton("Save Log", this);
    btnSave->setGeometry(20, 100, 320, 35);
    connect(btnSave, &QPushButton::clicked, this, &MainWindow::saveLogToFile);

    label = new QLabel("Click a button...", this);
    label->setGeometry(20, 150, 320, 70);

    shapeList.append(&circle);
    shapeList.append(&rect);
}

MainWindow::~MainWindow() {
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

void MainWindow::drawShape(oop::Shape* s) {
    if (s == nullptr) {
        label->setText("No shape to draw");
        return;
    }
    oop::DrawingTool tool(s);
    label->setText(tool.performDraw());
}

void MainWindow::clearShape() {
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
        if (s != nullptr) {
            out += s->draw() + "\n";
        }
    }
    label->setText(out.trimmed());
}

/*
 * vraag 38: useful usage of (modern) file-I/O
 * - QSaveFile: atomic write (veiliger dan QFile)
 * - QStandardPaths: platform-onafhankelijke folder (Documents)
 * - Logt shape draw output naar een .txt bestand
 */
void MainWindow::saveLogToFile() {
    const QString docs = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    const QString dirPath = docs.isEmpty() ? QDir::homePath() : docs;

    const QString fileName =
        "shape_log_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".txt";
    const QString fullPath = QDir(dirPath).filePath(fileName);

    QSaveFile file(fullPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        label->setText("Failed to open file for writing");
        return;
    }

    QTextStream out(&file);
    out << "Shape log (" << QDateTime::currentDateTime().toString(Qt::ISODate) << ")\n\n";

    // log shapes uit container (nuttig)
    for (oop::Shape* s : shapeList) {
        if (s != nullptr) {
            out << s->describe() << "\n";
            out << s->draw() << "\n\n";
        }
    }

    // log ook huidige dynamic shape (als die bestaat)
    if (dynamicShape != nullptr) {
        out << "Dynamic shape:\n";
        out << dynamicShape->describe() << "\n";
        out << dynamicShape->draw() << "\n";
    }

    if (!file.commit()) {
        label->setText("Failed to save file");
        return;
    }

    label->setText("Saved log to Documents");
}
