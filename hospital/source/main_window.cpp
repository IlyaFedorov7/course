#include "main_window.h"
#include <iostream>
#include <ctime>
#include <map>

MainWindow::MainWindow(QWidget* parent) : 
	QMainWindow(parent) {
	setlocale(LC_ALL, "Russian");
	ui.setupUi(this);
	// open database
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("data.db");
	db.open();
	model = new QSqlQueryModel;
	editorWindow = new Editor;
	shifts_modal = new Shifts_modal;
	call_modal = new Call_modal;
	connect(editorWindow, &Editor::comeback, this, &MainWindow::showMain);
	// connect buttons
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(search()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(newEmployee()));
	updateTables();
	connect(ui.employeeTable, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onTableClicked(const QModelIndex&)));
	connect(ui.shiftTable, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(addShift(const QModelIndex&)));
	connect(ui.callTable, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(addCall(const QModelIndex&)));
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &MainWindow::changePage);
	//tables styling
	ui.employeeTable->verticalHeader()->setVisible(false);
	ui.shiftTable->verticalHeader()->setVisible(false);
}

void MainWindow::showMain() {
	updateTables();
	this->show();
}

void MainWindow::updateTables() {
	int currentPage = ui.tabWidget->currentIndex();
	if (currentPage == 0) {
		addData(R"(
	select ID, FIO as ФИО, Kfalifikacia as Квалификация, Opyt as Опыт, Obrazovanie as Образование, 
	Name_type as Специализация, Vyplata_gen-Vyplata_oklad*coeff_experience-increase as Выплата_за_смены, increase as Выплата_за_вызовы, Vyplata_gen as Общая_выплата from Vrach 
	inner join Stazh on Kod_S_Stazh=Kod_S 
	inner join Specializacia_and_Vrach on ID=ID_Vrach 
	inner join Specializacia on Kod_Sp_Specializacia=Kod_Sp
	inner join ZpVedomost on Kod_Z_ZpVedomost=Kod_Z
	where FIO like :start)", ui.employeeTable);
	}
	else if (currentPage == 1) {
		addData(R"(
	select ID, FIO as ФИО, Kfalifikacia as Квалификация, Name_type as Специализация, 
	count(Smena_and_Vrach.ID_Vrach) as Количество_смен, coeff_shifts as Коэффициент, 'добавить смену' as Добавление from Vrach 
	inner join Stazh on Kod_S_Stazh=Kod_S 
	inner join Specializacia_and_Vrach on ID= Specializacia_and_Vrach.ID_Vrach 
	inner join Specializacia on Kod_Sp_Specializacia=Kod_Sp
	inner join ZpVedomost on Kod_Z_ZpVedomost=Kod_Z
	left join Smena_and_Vrach on ID=Smena_and_Vrach.ID_Vrach
	left join Smena on Kod_Sm_Smena=Kod_Sm
	where FIO like :start
	group by ID)", ui.shiftTable);
	}
	else {
		addData(R"(
	select ID, FIO as ФИО, Kfalifikacia as Квалификация, Name_type as Специализация, 
	count(Vyzovy_and_Vrach.ID_Vrach) as Количество_вызовов, increase as Прибавка_за_вызовы, 'Добавить вызов' as Добавить from Vrach 
	inner join Stazh on Kod_S_Stazh=Kod_S 
	inner join Specializacia_and_Vrach on ID= Specializacia_and_Vrach.ID_Vrach 
	inner join Specializacia on Kod_Sp_Specializacia=Kod_Sp
	inner join ZpVedomost on Kod_Z_ZpVedomost=Kod_Z
	left join Vyzovy_and_Vrach on ID=Vyzovy_and_Vrach.ID_Vrach
	left join Vyzovy on Kod_V=Kod_V_Vyzovy
	where FIO like :start
	group by ID)", ui.callTable);
	}
	//QSqlQueryModel* shiftModel = new QSqlQueryModel();
	//shiftModel->setQuery("select ");
	//ui.shiftTable->setModel(shiftModel);

}

void MainWindow::addData(std::string request, QTableView *table) {
	QSqlQuery query;
	query.prepare(request.c_str());
	query.bindValue(":start", QString("%1%").arg(filter));
	query.exec();
	model->setQuery(query);
	table->setModel(model);
	table->resizeColumnsToContents();
	table->setColumnHidden(0, true);
}

void MainWindow::newEmployee() {
	int currentPage = ui.tabWidget->currentIndex();
	if (currentPage == 0) {
		filter = "";
		ui.lineEdit->setText("");
		editorWindow->prepareEditor(-1);
		editorWindow->show();
		this->hide();
	}
	else if (currentPage == 1) {
		shifts_modal->setCoeff();
		shifts_modal->show();
	}
	else {
		call_modal->setIncrease();
		call_modal->show();
	}
}

void MainWindow::onTableClicked(const QModelIndex& index) {
	editorWindow->prepareEditor(ui.employeeTable->model()->data(ui.employeeTable->model()->index(index.row(), 0)).toInt());
	this->hide();
	editorWindow->show();
}

void MainWindow::search() {
	filter = ui.lineEdit->text();
	updateTables();
}

void MainWindow::addShift(const QModelIndex& index) {
	if (index.column() == 6) {
		QSqlQuery query;
		query.exec("select coeff from Current_values");
		query.first();
		float coeff = query.value(0).toFloat();
		query.prepare(R"(insert into Smena(Coeff_2, Data_S) values
		(:coeff, :time))");
		query.bindValue(":time", time(0));
		query.bindValue(":coeff", coeff);
		query.exec();

		int shiftId =  query.lastInsertId().toInt();
		query.prepare(R"(insert into Smena_and_Vrach values
		(:shiftId, :id))");
		query.bindValue(":shiftId", shiftId);
		query.bindValue(":id", ui.shiftTable->model()->data(ui.shiftTable->model()->index(index.row(), 0)).toInt());
		query.exec();

		query.exec(R"(select Coeff_2, ID_Vrach from Smena
		inner join Smena_and_Vrach on Kod_Sm_Smena=Kod_Sm)");
		std::map<int, float> dict;
		while (query.next()) {
			int id = query.value(1).toInt();
			dict.count(id) == 1 ? dict[id] *= query.value(0).toFloat() : dict[id] = query.value(0).toFloat();
		}
		for (auto& item : dict) {
			query.prepare("update ZpVedomost set coeff_shifts=:fullCoeff, Vyplata_gen=ROUND(Vyplata_oklad*coeff_experience*:fullCoeff)+increase where Kod_Z=(select Kod_Z_ZpVedomost from Vrach where ID=:id)");
			query.bindValue(":fullCoeff", item.second);
			query.bindValue(":id", item.first);
			std::cout << query.exec();
			qDebug() << query.lastError();
		}
		updateTables();
		//model->setQuery("select * from Vrach");
		//ui.shiftTable->setColumnHidden(0, false);
	}
}

void MainWindow::addCall(const QModelIndex& index) {
	if (index.column() == 6) {
		QSqlQuery query;
		query.exec("select increase from Current_values");
		query.first();
		int increase = query.value(0).toInt();
		query.prepare("insert into Vyzovy(Data, Nadbavka) values (:date, :increase)");
		query.bindValue(":date", time(0));
		query.bindValue(":increase", increase);
		std::cout << query.exec();

		int callId = query.lastInsertId().toInt();
		query.prepare("insert into Vyzovy_and_Vrach(Kod_V_Vyzovy, ID_Vrach) values (:callId, :id)");
		query.bindValue(":callId", callId);
		query.bindValue(":id", ui.callTable->model()->data(ui.callTable->model()->index(index.row(), 0)).toInt());
		std::cout<<query.exec();

		query.prepare(R"(update ZpVedomost set increase=(select SUM(Nadbavka) from Vyzovy 
		where Kod_V in (select Kod_V_Vyzovy from Vyzovy_and_Vrach where ID_Vrach=:id))
		where Kod_Z=(select Kod_Z_ZpVedomost from Vrach where ID=:id))");
		query.bindValue(":id", ui.callTable->model()->data(ui.callTable->model()->index(index.row(), 0)).toInt());
		std::cout << query.exec();
		qDebug()<<query.lastError();

		query.prepare("update ZpVedomost set Vyplata_gen = ROUND(Vyplata_oklad * coeff_experience * coeff_shifts)+increase");
		std::cout << query.exec();
		updateTables();
	}
}

void MainWindow::changePage() {
	filter = "";
	ui.lineEdit->setText("");
	updateTables();
	ui.tabWidget->currentIndex() == 0 ? ui.pushButton_2->setText("Добавить") : ui.pushButton_2->setText("Настроить");
}