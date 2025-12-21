#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QTimer>
#include <QFutureWatcher>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    // vraag 43: signals/slots
    void shapeChanged(const QString&);

private slots:
    void drawCircle();
    void drawRectangle();
    void clearShape();
    void updateLabel(const QString&);

private:
    QLabel* label = nullptr; // vraag 37: nullptr

    oop::Shape* dynamicShape = nullptr; // vraag 32, 33
    QVector<oop::Shape*> shapes;        // vraag 36

    QTimer timer;                       // vraag 42
};

#endif
