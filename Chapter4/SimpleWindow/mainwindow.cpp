#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("MY WINDOW");
    QMenuBar *barMenu = menuBar();
    QMenu *fileMenu = barMenu->addMenu("&File");
    QAction *newAction = fileMenu->addAction(QPixmap("new.png"), "&new");
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    connect(newAction, &QAction::triggered, this, [&](){
        QMessageBox::information(this, "info new", "newAction Triggered");
    });

    QAction *openAction = fileMenu->addAction(QPixmap("open.png"), "open");
    openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    connect(openAction, &QAction::triggered, this, [&](){
        QMessageBox::information(this, "info open", "openAction Triggered");
    });

    fileMenu->addSeparator();
    QAction *quitAction = fileMenu->addAction(QPixmap("quit.png"), "quit");
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, &QAction::triggered, this, &QMainWindow::close);

    QMenu *helpMenu = barMenu->addMenu("Help");
    QAction *aboutAction = helpMenu->addAction("About");

    QToolBar *barTool = new QToolBar;
    addToolBar(Qt::LeftToolBarArea, barTool);
    barTool->addAction(newAction);
    barTool->addAction(openAction);
    barTool->addAction(quitAction);




}
