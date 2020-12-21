#include "main_window.h"
#include <iostream>
#include <QApplication>
#include "hospital.h"


using namespace std;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow win;
	win.show();
	return app.exec();
}
