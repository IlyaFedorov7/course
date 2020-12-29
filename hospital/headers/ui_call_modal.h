/********************************************************************************
** Form generated from reading UI file 'call_modal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALL_MODAL_H
#define UI_CALL_MODAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
/// Класс интерефейса для call_modal
class Ui_call_modal
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(439, 249);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(400, 200));
        widget->setAutoFillBackground(true);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 171, 41));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 150, 171, 41));
        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 90, 171, 31));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 371, 41));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\200\320\270\320\261\320\260\320\262\320\272\321\203 \320\267\320\260 \320\262\321\213\320\267\320\276\320\262", nullptr));
    } // retranslateUi

};


QT_END_NAMESPACE

#endif // UI_CALL_MODAL_H
