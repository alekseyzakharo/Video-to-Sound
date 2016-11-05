#include "image2sound.h"
#include <QtWidgets/QApplication>
#include "main.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	image2sound w;
	w.show();
	return a.exec();
}
