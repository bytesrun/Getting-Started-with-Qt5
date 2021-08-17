#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dragtextedit.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
private slots:
    void updateStatusBar();
private:
    DragTextEdit *slateDragTextEdit;
};

#endif // MAINWINDOW_H
