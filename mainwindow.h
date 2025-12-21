#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>

#include <QFutureWatcher>   // vraag 41: threads (watch async task)

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void drawCircle();
    void drawRectangle();
    void clearShape();
    void drawAllShapes();

    void saveLogToFile();          // bestaat al
    void saveLogToFileAsync();     // vraag 41: threaded version

private:
    QLabel* label = nullptr;

    void drawShape(oop::Shape* s);

    oop::Shape* dynamicShape = nullptr;
    QVector<oop::Shape*> shapeList;

    // vraag 41: useful usage of threads
    // Watcher voor QtConcurrent task (runs in thread pool)
    QFutureWatcher<bool> saveWatcher;
};

#endif // MAINWINDOW_H
