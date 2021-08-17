#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow wnd;
    wnd.resize(300, 300);
    wnd.show();
    app.exec();
}
