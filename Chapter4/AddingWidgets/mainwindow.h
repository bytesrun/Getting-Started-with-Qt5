#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QtGui>
//#include <Qt>
#include <QToolBar>
#include <QTableView>
#include <QHeaderView>

#include <QMessageBox>
#include <QInputDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
private slots:
    void saveButtonClicked();
    void aboutDialog();
    void clearAllRecords();
    void deleteSaveRecord();

private:
    //Widgets
    QWidget *mainWidget;
    QVBoxLayout *centralWidgetLayout;
    QGridLayout *formLayout;
    QHBoxLayout *buttonLayout;
    QLabel *nameLabel;
    QLabel *dateOfBirthLabel;
    QLabel *phoneNumberLabel;
    QPushButton *savePushButton;
    QPushButton *newPushButton;
    QPushButton *clearPushButton;
    QLineEdit *nameLineEdit;
    QDateEdit *dateOfBirthEdit;
    QLineEdit *phoneNumberEdit;
    QTableView *appTable;
    QStandardItemModel *model;

    //Menus
    QMenu *fileMenu;
    QMenu *helpMenu;

    //Actions
    QAction *quitAction;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *cancelAction;
    QAction *openAction;
    QAction *newAction;
    QAction *aboutQtAction;
    QAction *newToolBarAction;
    QAction *openToolBarAction;
    QAction *closeToolBarAction;
    QAction *clearToolBarAction;
    QAction *deleteOneEntryToolBarAction;

    //ToolBar
    QToolBar *toolBar;

    //Icons
    QPixmap newIcon;
    QPixmap openIcon;
    QPixmap closeIcon;
    QPixmap clearIcon;
    QPixmap deleteIcon;

    //init methods
    void clearFields();
    void createIcons();
    void createMenuBar();
    void createToolBar();
    void setupSingnalsAndSlot();
    void setupCoreWidgets();
};

#endif // MAINWINDOW_H
