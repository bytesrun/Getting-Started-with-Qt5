#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QLabel label("Hello World");
    label.setStyleSheet("QLabel::hover {color:rgb(60, 179, 113)} QLabel {color: red} QLabel {background: yellow}");

	label.show();
	app.exec();
}
