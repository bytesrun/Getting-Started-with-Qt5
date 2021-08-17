#include <QApplication>
#include <QWidget>
#include <QDial>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QSlider>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget *wnd = new QWidget;
    wnd->setWindowTitle("Signals and Slots");

    void (QLabel::*pfn)(int) = &QLabel::setNum;
    void (QLCDNumber::*pfn2)(int) = &QLCDNumber::display;

    QWidget *sub = new QWidget;
    QDial *dial = new QDial;
    QLabel *label = new QLabel("0");
    //QObject::connect(dial, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));

    QObject::connect(dial, &QDial::valueChanged, label, pfn);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(dial);
    vLayout->addWidget(label);
    sub->setLayout(vLayout);

    QWidget *sub2 = new QWidget;
    QDial *dial2 = new QDial;
    QLabel *label2 = new QLabel("0");
    dial2->setNotchesVisible(true);
    label2->setAlignment(Qt::AlignHCenter);
    QLCDNumber *lcd = new QLCDNumber;
    lcd->setPalette(Qt::red);
    QObject::connect(dial2, &QDial::valueChanged, label2, pfn);
    QObject::connect(dial2, &QDial::valueChanged, lcd, pfn2);
    QVBoxLayout *vLayout2 = new QVBoxLayout;
    vLayout2->addWidget(dial2);
    vLayout2->addWidget(label2);
    vLayout2->addWidget(lcd);
    sub2->setLayout(vLayout2);

    QWidget *sub3 = new QWidget;
    QDial *dial3 = new QDial;
    QSlider *sld = new QSlider(Qt::Horizontal);
    QLCDNumber *lcd2 = new QLCDNumber;

    dial3->setNotchesVisible(true);
    dial3->setMinimum(0);
    dial3->setMaximum(100);
    sld->setTickPosition(QSlider::TicksAbove);
    sld->setTickInterval(10);
    sld->setSingleStep(1);
    sld->setMinimum(0);
    sld->setMaximum(100);
    lcd2->setPalette(Qt::red);
    QObject::connect(dial3, &QDial::valueChanged, lcd2, pfn2);
    QObject::connect(dial3, &QDial::valueChanged, sld, &QSlider::setValue);

    QObject::connect(sld, &QSlider::valueChanged, lcd2, pfn2);
    QObject::connect(sld, &QSlider::valueChanged, dial3, &QDial::setValue);

    QVBoxLayout *vLayout3 = new QVBoxLayout;
    vLayout3->addWidget(dial3);
    vLayout3->addWidget(sld);
    vLayout3->addWidget(lcd2);
    sub3->setLayout(vLayout3);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(sub);
    layout->addWidget(sub2);
    layout->addWidget(sub3);
    wnd->setLayout(layout);
    wnd->show();
    app.exec();
}
