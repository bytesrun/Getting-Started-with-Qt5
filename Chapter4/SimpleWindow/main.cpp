#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow wnd;
    wnd.show();
    app.exec();
}
