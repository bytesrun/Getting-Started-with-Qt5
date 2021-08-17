#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Form in Window");
    setFixedSize(500, 500);
    setWindowIcon(QIcon("windows.png"));
    createIcons();
    setupCoreWidgets();
    createMenuBar();
    createToolBar();
    centralWidgetLayout->addLayout(formLayout);
    centralWidgetLayout->addWidget(appTable);
    centralWidgetLayout->addLayout(buttonLayout);
    mainWidget->setLayout(centralWidgetLayout);
    setCentralWidget(mainWidget);
    setupSingnalsAndSlot();
}

void MainWindow::createIcons()
{
    newIcon = QPixmap("new.png");
    openIcon = QPixmap("open.png");
    closeIcon = QPixmap("quit.png");
    clearIcon = QPixmap("clear.png");
    deleteIcon = QPixmap("trash.png");
}

void MainWindow::setupCoreWidgets()
{
    mainWidget = new QWidget;
    centralWidgetLayout = new QVBoxLayout;
    formLayout = new QGridLayout;
    buttonLayout = new QHBoxLayout;
    nameLabel = new QLabel("Name:");
    dateOfBirthLabel = new QLabel("Date of Birth:");
    phoneNumberLabel = new QLabel("Phone Number");
    savePushButton = new QPushButton("Save");
    newPushButton = new QPushButton("Clear All");
    nameLineEdit = new QLineEdit;
    dateOfBirthEdit = new QDateEdit(QDate::currentDate());
    phoneNumberEdit = new QLineEdit;

    //TableView
    appTable = new QTableView;
    model = new QStandardItemModel(1, 3, this);
    appTable->setContextMenuPolicy(Qt::CustomContextMenu);
    appTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Date of Birth"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Phone Number"));

    appTable->setModel(model);

    QStandardItem *firstItem = new QStandardItem("G. Shone");
    QDate dateOfBirth(1980, 1, 1);
    QStandardItem *secondItem = new QStandardItem(dateOfBirth.toString());
    QStandardItem *thirdItem = new QStandardItem("05443394858");
    model->setItem(0, 0, firstItem);
    model->setItem(0, 1, secondItem);
    model->setItem(0, 2, thirdItem);

    formLayout->addWidget(nameLabel, 0, 0);
    formLayout->addWidget(nameLineEdit, 0, 1);
    formLayout->addWidget(dateOfBirthLabel, 1, 0);
    formLayout->addWidget(dateOfBirthEdit, 1, 1);
    formLayout->addWidget(phoneNumberLabel, 2, 0);
    formLayout->addWidget(phoneNumberEdit, 2, 1);

    buttonLayout->addStretch();
    buttonLayout->addWidget(savePushButton);
    buttonLayout->addWidget(newPushButton);
}

void MainWindow::createMenuBar()
{
    //Setup File Menu
    QMenuBar *barMenu = menuBar();
    fileMenu = new QMenu("&File");
    quitAction = new QAction(closeIcon, "Quit", this);
    quitAction->setShortcuts(QKeySequence::Quit);
    newAction = new QAction(newIcon, "&New", this);
    newAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    openAction = new QAction(openIcon, "&Open", this);
    openAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    barMenu->addMenu(fileMenu);

    helpMenu = new QMenu("&Help");
    aboutAction = new QAction("About", this);
    aboutAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    helpMenu->addAction(aboutAction);

    barMenu->addMenu(helpMenu);
}

void MainWindow::createToolBar()
{
    toolBar = new QToolBar;
    //toolBar->setMovable(false);
    newToolBarAction = newAction;
    openToolBarAction = openAction;
    //toolBar->addAction("hello");
    toolBar->addAction(newToolBarAction);
    toolBar->addAction(openToolBarAction);
    toolBar->addSeparator();
    clearToolBarAction = toolBar->addAction(QIcon(clearIcon), "Clear All");
    deleteOneEntryToolBarAction = toolBar->addAction(QIcon(deleteIcon), "Delete a record");
    closeToolBarAction = toolBar->addAction(QIcon(closeIcon), "Quit Application");

    addToolBar(toolBar);
}

void MainWindow::saveButtonClicked()
{
    QStandardItem *name = new QStandardItem(nameLineEdit->text());
    QStandardItem *dob = new QStandardItem(dateOfBirthEdit->date().toString());
    QStandardItem *phoneNumber = new QStandardItem(phoneNumberEdit->text());
    model->appendRow({name, dob, phoneNumber});
    clearFields();
    QMessageBox::information(this, tr("My System"), tr("Record saved successfully!"),
                             QMessageBox::Ok | QMessageBox::Default,
                             QMessageBox::NoButton, QMessageBox::NoButton);
}

void MainWindow::setupSingnalsAndSlot()
{
    connect(quitAction, &QAction::triggered, this, &QApplication::quit);
    connect(closeToolBarAction, &QAction::triggered, this, &QApplication::quit);
    connect(savePushButton, &QPushButton::clicked, this, &MainWindow::saveButtonClicked);

    connect(aboutAction, &QAction::triggered, this, &MainWindow::aboutDialog);
    connect(clearToolBarAction, &QAction::triggered, this, &MainWindow::clearAllRecords);
    connect(deleteOneEntryToolBarAction, &QAction::triggered, this, &MainWindow::deleteSaveRecord);
    clearPushButton = newPushButton;
    connect(clearPushButton, &QPushButton::clicked, this, &MainWindow::clearAllRecords);
}

void MainWindow::clearFields()
{
    nameLineEdit->clear();
    //phoneNumberEdit->clear();
    phoneNumberEdit->setText("");
    QDate dateOfBirth(1980, 1, 1);
    dateOfBirthEdit->setDate(dateOfBirth);
}

void MainWindow::deleteSaveRecord()
{
    bool ok;
    int rowId = QInputDialog::getInt(this, tr("Select Row to delete"),
                  tr("Please enter Row ID of record (Eg. 1)"),
                  1, 1, model->rowCount(), 1, &ok);
    if (ok)
    {
        model->removeRow(rowId - 1);
    }

}

void MainWindow::clearAllRecords()
{
    int status = QMessageBox::question(this, tr("Delete all Records"),
                    tr("This operation will delete all saved records." "<p>Do you want to"
                       "remove all saved records?"),
                    tr("Yes, Delete all records"), tr("No !"), QString(), 1, 1);
    qDebug() << "status: " << status;

    if (status == 0)
    {
        int rowS = model->rowCount();
        model->removeRows(0, rowS);
    }

}

void MainWindow::aboutDialog()
{
    QMessageBox::about(this, "About My System", "My System 2.0 <p>Copyright &copy; 2021 Inc."
                       "This is a simple application to demonstrate the use of windows, "
                                                "tool bars, menus and dialog boxes");

}
