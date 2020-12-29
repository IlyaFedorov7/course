/********************************************************************************
** Form generated from reading UI file 'ui_shifts_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIFTS_EDITOR_H
#define UI_SHIFTS_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
/// Класс графического интерфейса shifts_modal
class Ui_shifts_modal
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(422, 218);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(400, 200));
        widget->setAutoFillBackground(true);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 361, 61));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(30, 80, 151, 31));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 140, 151, 51));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 140, 151, 51));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\274\320\265\320\275\321\213", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \321\201\320\274\320\265\320\275\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif // UI_SHIFTS_EDITOR_H
