#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QStringList>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget *wnd = new QWidget;
    wnd->setWindowTitle("MyLayout");

    QLabel *label = new QLabel("Open Happiness");
    QLineEdit *firstNameEdit = new QLineEdit;
    QLineEdit *lastNameEdit = new QLineEdit;
    QSpinBox *spnBox = new QSpinBox;
    spnBox->setRange(1, 100);
    QStringList stLst = {"unemployed", "employed", "NA"};
    QComboBox *cbBox = new QComboBox;
    cbBox->addItems(stLst);

#ifndef NULL
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 0);
    layout->addWidget(firstNameEdit, 0, 1);
    layout->addWidget(lastNameEdit, 0, 2);
    layout->addWidget(spnBox, 1, 0);
    layout->addWidget(cbBox, 1, 1, 1, 2);
#endif
    //QHBoxLayout, QVBoxLayout
    QFormLayout *layout = new QFormLayout;
    layout->addRow("First Name", firstNameEdit);
    layout->addRow("Last Name", lastNameEdit);
    layout->addRow("Age", spnBox);
    layout->addRow("Employment Status", cbBox);

    wnd->setLayout(layout);
    wnd->show();

    app.exec();
}
