#include "editor.h"
#include <QtSql>
#include <iostream>

Editor::Editor(QWidget* parent) :
	QMainWindow(parent) {
	ui.setupUi(this);
	ui.label_7->setText("Коэфф. за опыт");

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(update()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(deleteRecord()));

	ui.spinBox->setMaximum(1000000);
	ui.doubleSpinBox->setMaximum(50.0);
}

void Editor::prepareEditor(int idVal) {
	id = idVal;
	idVal == -1 ? ui.pushButton_3->hide() : ui.pushButton_3->show();
	if (idVal == -1) setValues();
	else {
		QSqlQuery *query = new QSqlQuery();
		query->prepare(R"(select FIO, Kfalifikacia, Opyt, Obrazovanie, Name_type, Oklad, Coeff_1 from Vrach 
	inner join Stazh on Kod_S_Stazh=Kod_S 
	inner join Specializacia_and_Vrach on ID=ID_Vrach 
	inner join Specializacia on Kod_Sp_Specializacia=Kod_Sp
	where ID = ?)");
		query->addBindValue(idVal);
		query->exec();
		query->first();
		setValues(query->value(0).toString().toStdString(), query->value(1).toString().toStdString(), query->value(2).toString().toStdString(), 
			query->value(3).toString().toStdString(), query->value(4).toString().toStdString(), query->value(5).toInt(), query->value(6).toFloat());
	}
}
void Editor::setValues(std::string nameVal, std::string qualificationVal, std::string experienceVal, std::string educationVal,
	std::string specializationVal, int payVal, float coeffVal) {
	ui.lineEdit->setText(nameVal.c_str());
	ui.lineEdit_2->setText(qualificationVal.c_str());
	ui.lineEdit_3->setText(experienceVal.c_str());
	ui.lineEdit_4->setText(educationVal.c_str());
	ui.lineEdit_5->setText(specializationVal.c_str());
	ui.spinBox->setValue(payVal);
	ui.doubleSpinBox->setValue(coeffVal);
}
void Editor::exit() {
	emit comeback();
	this->close();
}
void Editor::update() {
	QSqlQuery *query = new QSqlQuery();

	if (id == -1) {
		query->prepare(R"(insert into Stazh(Obrazovanie, Opyt, Coeff_1) values (:education, :experience, :coeff);)");
		query->bindValue(":education", ui.lineEdit_4->text());
		query->bindValue(":experience", ui.lineEdit_3->text());
		query->bindValue(":coeff", ui.doubleSpinBox->value());
		std::cout << query->exec();
		int experienceId = query->lastInsertId().toInt();
		std::cout << query->lastInsertId().toInt() << std::endl;

		query->prepare(R"(insert into ZpVedomost(coeff_experience, Vyplata_oklad, Vyplata_gen) values(:coeffExp, :pay, :generalPay))");
		query->bindValue(":coeffExp", ui.doubleSpinBox->value());
		query->bindValue(":pay", ui.spinBox->value());
		query->bindValue(":generalPay", ui.spinBox->value() * ui.doubleSpinBox->value());
		std::cout << query->exec();
		int salaryId = query->lastInsertId().toInt();
		std::cout << query->lastInsertId().toInt() << std::endl;

		query->prepare(R"(insert into Specializacia(Name_type, Oklad) values(:specialization, :salary))");
		query->bindValue(":specialization", ui.lineEdit_5->text());
		query->bindValue(":salary", ui.spinBox->value());
		std::cout << query->exec();
		int specializationId = query->lastInsertId().toInt();
		std::cout << query->lastInsertId().toInt() << std::endl;

		query->prepare(R"(insert into Vrach(Kod_Z_ZpVedomost, Kod_S_Stazh, FIO, Kfalifikacia) values (:salaryId, :experienceId, :name, :qualification))");
		query->bindValue(":salaryId", salaryId);
		query->bindValue(":experienceId", experienceId);
		query->bindValue(":name", ui.lineEdit->text());
		query->bindValue(":qualification", ui.lineEdit_2->text());
		std::cout << query->exec();
		int doctorId = query->lastInsertId().toInt();
		std::cout << query->lastInsertId().toInt() << std::endl;

		query->prepare(R"(insert into Specializacia_and_Vrach(Kod_Sp_Specializacia, ID_Vrach) values(:specializationId, :doctorId))");
		query->bindValue(":specializationId", specializationId);
		query->bindValue(":doctorId", doctorId);
		std::cout << query->exec();
	}
	else {
		query->prepare(R"(update Stazh set Obrazovanie = :education, Opyt = :experience, Coeff_1 = :coeff
		where Kod_S = (select Kod_S_Stazh from Vrach where ID = :id))");
		query->bindValue(":id", id);
		query->bindValue(":education", ui.lineEdit_4->text());
		query->bindValue(":experience", ui.lineEdit_3->text());
		query->bindValue(":coeff", ui.doubleSpinBox->value());
		std::cout << query->exec();

		query->prepare(R"(update ZpVedomost set coeff_experience = :coeffExp, Vyplata_oklad = :pay, Vyplata_gen = :generalPay
		where Kod_Z = (select Kod_Z_ZpVedomost from Vrach where ID = :id))");
		query->bindValue(":id", id);
		query->bindValue(":coeffExp", ui.doubleSpinBox->value());
		query->bindValue(":pay", ui.spinBox->value());
		query->bindValue(":generalPay", ui.spinBox->value() * ui.doubleSpinBox->value());
		std::cout << query->exec();

		query->prepare(R"(update Specializacia set Name_type = :specialization, Oklad = :salary
		where Kod_Sp = (select Kod_Sp_Specializacia from Specializacia_and_Vrach 
		where ID_Vrach = :id))");
		query->bindValue(":id", id);
		query->bindValue(":specialization", ui.lineEdit_5->text());
		query->bindValue(":salary", ui.spinBox->value());
		std::cout << query->exec();

		query->prepare(R"(update Vrach set FIO = :name, Kfalifikacia = :qualification
		where ID = :id)");
		query->bindValue(":id", id);
		query->bindValue(":name", ui.lineEdit->text());
		query->bindValue(":qualification", ui.lineEdit_2->text());
		std::cout << query->exec();
	}
	exit();
}

void Editor::deleteRecord() {
	QSqlQuery query;
	query.prepare(R"(delete from Specializacia_and_Vrach
	where ID_Vrach = :id)");
	query.bindValue(":id", id);
	std::cout << query.exec();

	query.prepare(R"(delete from Vziskania_and_Vrach
	where ID_Vrach = :id)");
	query.bindValue(":id", id);
	std::cout << query.exec();

	query.prepare(R"(delete from Vyzovy_and_Vrach
	where ID_Vrach = :id)");
	query.bindValue(":id", id);
	std::cout << query.exec();

	query.prepare(R"(delete from Smena_and_Vrach
	where ID_Vrach = :id)");
	query.bindValue(":id", id);
	std::cout << query.exec();

	query.prepare(R"(delete from Vrach
	where ID = :id)");
	query.bindValue(":id", id);
	std::cout << query.exec();

	exit();

}
