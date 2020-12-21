#include "shifts_modal.h"
#include <QtSql>

Shifts_modal::Shifts_modal (QWidget* parent) :
	QDialog(parent) {
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(updateCoeff()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

void Shifts_modal::setCoeff() {
	QSqlQuery query;
	qDebug()<<query.exec("select coeff from Current_values");
	query.first();
	ui.doubleSpinBox->setValue(query.value(0).toDouble());
}

void Shifts_modal::updateCoeff() {
	QSqlQuery query;
	query.prepare("update Current_values set coeff=:coeff");
	query.bindValue(":coeff", (float) ui.doubleSpinBox->value());
	qDebug() << query.exec();
	this->close();
}
