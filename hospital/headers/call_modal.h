#pragma once
#include "ui_call_modal.h"
#include <QDialog>

class Call_modal:public QDialog {
	Q_OBJECT
public:
	Call_modal(QWidget* parent = nullptr);
	void setIncrease();
private:
	Ui_call_modal ui;
private slots:
	void updateIncrease();
};