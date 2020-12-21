#pragma once
#include <QDialog>
#include "ui_shifts_modal.h"

class Shifts_modal : public QDialog {
	Q_OBJECT
public:
	Shifts_modal(QWidget* parent = nullptr);
	void setCoeff();
private:
	Ui_shifts_modal ui;
private slots:
	void updateCoeff();
};