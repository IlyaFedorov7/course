#pragma once
#include <QDialog>
#include "ui_shifts_modal.h"
/// Класс модального окна, предназначенного для изменения коэффициента за смены
class Shifts_modal : public QDialog {
	Q_OBJECT
public:
	Shifts_modal(QWidget* parent = nullptr);
	/// Позволяет поменять коэффициент за смену
	void setCoeff();
private:
	Ui_shifts_modal ui;
private slots:
	void updateCoeff();
};