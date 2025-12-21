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

    QPushButton* btnInfo = new QPushButton("Show Info", this);
    connect(btnInfo, &QPushButton::clicked, this, [this]() {
        if (dynamicShape != nullptr) {
            label->setText(dynamicShape->describe());
        } else {
            label->setText("No dynamic shape available");
        }
        statusTimer.start(); // vraag 42: timer starten
    });

    label = new QLabel("Click a button...", this);

    shapeList.append(&circle);
    shapeList.append(&rect);

    /*
     * vraag 42: useful Qt class (QTimer)
     * Wordt gebruikt om statusberichten automatisch te wissen na 3 seconden.
     */
    statusTimer.setSingleShot(true);
    statusTimer.setInterval(3000); // 3 seconden
    connect(&statusTimer, &QTimer::timeout, this, &MainWindow::clearStatusMessage);

    connect(&saveWatcher, &QFutureWatcher<bool>::finished, this, [this]() {
        label->setText(saveWatcher.result() ? "Saved log (async)" : "Async save failed");
        statusTimer.start(); // auto-clear message
    });
}

MainWindow::~MainWindow() {
    if (dynamicShape != nullptr) {
        delete dynamicShape;
        dynamicShape = nullptr;
    }
}

/*
 * vraag 42: QTimer slot
 * Wordt automatisch aangeroepen na timeout.
 */
void MainWindow::clearStatusMessage() {
    label->clear();
}


void MainWindow::drawRectangle() {
    clearShape();
    try {
        dynamicShape = new oop::Rectangle(60, 30, "Dynamic Rectangle");
        drawShape(dynamicShape);
    } catch (const std::bad_alloc&) {
        dynamicShape = nullptr;
        label->setText("Out of memory while creating Rectangle");
    }
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
 * vraag 41: useful usage of threads
 * We nemen een "snapshot" (QString) op de main thread, en schrijven dat weg in een worker thread.
 * Zo raken we geen UI vanuit de thread aan (thread-safe).
 */
void MainWindow::saveLogToFileAsync() {
    // voorkom overlappende saves
    if (saveWatcher.isRunning()) {
        label->setText("Async save already running...");
        return;
    }

    label->setText("Saving log in background...");

    // snapshot van data (veilig om door te geven naar thread)
    QString snapshot;
    snapshot += "Shape log (" + QDateTime::currentDateTime().toString(Qt::ISODate) + ")\n\n";

    for (oop::Shape* s : shapeList) {
        if (s != nullptr) {
            snapshot += s->describe() + "\n";
            snapshot += s->draw() + "\n\n";
        }
    }

    if (dynamicShape != nullptr) {
        snapshot += "Dynamic shape:\n";
        snapshot += dynamicShape->describe() + "\n";
        snapshot += dynamicShape->draw() + "\n";
    }

    // achtergrond thread: file-I/O
    auto future = QtConcurrent::run([snapshot]() -> bool {
        const QString docs = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        const QString dirPath = docs.isEmpty() ? QDir::homePath() : docs;

        const QString fileName =
            "shape_log_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".txt";
        const QString fullPath = QDir(dirPath).filePath(fileName);

        QSaveFile file(fullPath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return false;
        }

        QTextStream out(&file);
        out << snapshot;

        return file.commit();
    });

    saveWatcher.setFuture(future);
}
