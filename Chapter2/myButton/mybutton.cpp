#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QPushButton btn("button");
    btn.setStyleSheet("QPushButton {background: gray} QPushButton:hover {color: red}");
	btn.setToolTip("Click to do something");
	btn.show();
	app.exec();
}
