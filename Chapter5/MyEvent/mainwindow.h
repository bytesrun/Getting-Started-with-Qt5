#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMoveEvent>
#include <QLabel>
#include <QTimerEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void moveEvent(QMoveEvent *event);
    void timerEvent(QTimerEvent *event);
private:
    QLabel *currentDateTimeLabel;
signals:

public slots:
};

#endif // MAINWINDOW_H
