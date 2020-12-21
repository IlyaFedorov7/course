#pragma once
#include <QMainWindow>
#include <QString>
#include <QtSql>
#include "editor.h"
#include "shifts_modal.h"
#include "call_modal.h"
#include <ui_main_window.h>

class MainWindow : public QMainWindow {
	Q_OBJECT
public: 
	MainWindow(QWidget * parent = nullptr);
private:
	Ui_MainWindow ui;
	Editor* editorWindow;
	Shifts_modal* shifts_modal;
	Call_modal* call_modal;
	QSqlQueryModel* model;
	QString filter = "";
	void showMain();
	void addData(std::string request, QTableView *table);
private slots:
	void updateTables();
	void onTableClicked(const QModelIndex& index);
	void addShift(const QModelIndex& index);
	void addCall(const QModelIndex& index);
	void newEmployee();
	void changePage();
	void search();
};