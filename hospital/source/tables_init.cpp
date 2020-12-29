#include <fstream>
#include <string>
#include <QtSql>
#include <QApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	std::string line;
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("data.db");
	std::cout << db.open();
	QSqlQuery query;
	std::ifstream in("./tables_init.sql");
	std::cout<<in.is_open();
		while (getline(in, line)) {
			std::cout << query.exec(line.c_str());
			qDebug() << query.lastError().text();
		}
		in.close();
		//std::ifstream in1("../../../../hospital/tables_insert.sql");
		//while (getline(in1, line)) {
		//	std::cout << query.exec(line.c_str());
		//	qDebug() << query.lastError().text();
		//}
}