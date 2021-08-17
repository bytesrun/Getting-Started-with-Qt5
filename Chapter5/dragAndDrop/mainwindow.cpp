#include "mainwindow.h"
#include <QVBoxLayout>
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    slateDragTextEdit = new DragTextEdit;
    layout->addWidget(slateDragTextEdit);
    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
    statusBar()->showMessage(QString::number(0));
    connect(slateDragTextEdit, &DragTextEdit::textChanged, this, &MainWindow::updateStatusBar);
}

void MainWindow::updateStatusBar()
{
    int charCount = slateDragTextEdit->toPlainText().count();
    statusBar()->showMessage(QString::number(charCount));
}
