#pragma once
#include "ui_call_modal.h"
#include <QDialog>
/// Класс модального окна, служащего для изменения доплаты за вызовы
class Call_modal:public QDialog {
	Q_OBJECT
public:
	Call_modal(QWidget* parent = nullptr);
	/// Позволяет передать значения доплаты за вызовы
	void setIncrease();
private:
	Ui_call_modal ui;
private slots:
	void updateIncrease();
};