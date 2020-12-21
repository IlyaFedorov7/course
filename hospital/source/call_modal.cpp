#include "call_modal.h"
#include <QtSql>

Call_modal::Call_modal(QWidget* parent):
	QDialog(parent) {
	ui.setupUi(this);
	ui.spinBox->setMaximum(1000000); 

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(updateIncrease()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

void Call_modal::setIncrease() {
	QSqlQuery query;
	qDebug() << query.exec("select increase from Current_values");
	query.first();
	ui.spinBox->setValue(query.value(0).toInt());
}

void Call_modal::updateIncrease() {
	QSqlQuery query;
	query.prepare("update Current_values set increase=:increase");
	query.bindValue(":increase", (int) ui.spinBox->value());
	qDebug() << query.exec();
	close();
}