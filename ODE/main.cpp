#include "ode.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ODE w;
	w.show();
	return a.exec();
}
