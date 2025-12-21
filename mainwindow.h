#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QFutureWatcher>
#include <QTimer>

#include "circle.h"
#include "rectangle.h"
#include "drawingtool.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    /*
     * vraag 43: useful usage of signals/slots
     * Wordt uitgezonden wanneer de actieve shape verandert.
     */
    void shapeChanged(const QString& description);

private slots:
    void drawCircle();
    void drawRectangle();
    void clearShape();
    void drawAllShapes();
    void saveLogToFileAsync();

    // vraag 43: slot dat reageert op shapeChanged
    void updateStatusLabel(const QString& text);

    void clearStatusMessage();

private:
    QLabel* label = nullptr;

    void drawShape(oop::Shape* s);

    oop::Shape* dynamicShape = nullptr;
    QVector<oop::Shape*> shapeList;

    QFutureWatcher<bool> saveWatcher;
    QTimer statusTimer;
};

#endif // MAINWINDOW_H
