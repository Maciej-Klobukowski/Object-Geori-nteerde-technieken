#include <QApplication>
#include "mainwindow.h"

/*
 * Runs the application. No OOP concepts beyond class instantiation here.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
