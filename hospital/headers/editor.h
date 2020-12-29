#pragma once
#include <QMainWindow>
#include "ui_editor.h"
/// класс модального окна для добавления/редактирования сотрудников
class Editor : public QMainWindow {
	Q_OBJECT
public:
	Editor(QWidget* parent = nullptr);
	/// передает данные врача окну при нажатии вызове его едитора
	void prepareEditor(int ID);
private:
	Ui_Editor ui;
	int id = 0;
	void setValues(std::string nameVal = "", std::string qualificationVal = "", std::string experienceVal = "", std::string educationVal = "",
		std::string specializationVal = "", int payVal = 0, float callPayVal = 1);
private slots:
	void exit();
	void update();
	void deleteRecord();
signals:
	/// передает сигнал в главное окно
	void comeback();
};