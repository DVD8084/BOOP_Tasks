/********************************************************************************
** Form generated from reading UI file 'simulateForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATEFORM_H
#define UI_SIMULATEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_simulateForm
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *simulateForm)
    {
        if (simulateForm->objectName().isEmpty())
            simulateForm->setObjectName(QStringLiteral("simulateForm"));
        simulateForm->resize(341, 271);
        buttonBox = new QDialogButtonBox(simulateForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 230, 161, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        tableWidget = new QTableWidget(simulateForm);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 40, 301, 181));
        tableWidget->setRowCount(0);
        comboBox = new QComboBox(simulateForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 10, 131, 21));
        pushButton = new QPushButton(simulateForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 10, 41, 23));
        label = new QLabel(simulateForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 61, 21));
        lineEdit = new QLineEdit(simulateForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(52, 239, 91, 21));
        label_2 = new QLabel(simulateForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 240, 31, 16));

        retranslateUi(simulateForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), simulateForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), simulateForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(simulateForm);
    } // setupUi

    void retranslateUi(QDialog *simulateForm)
    {
        simulateForm->setWindowTitle(QApplication::translate("simulateForm", "Simulation Options", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("simulateForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("simulateForm", "Amount", nullptr));
        pushButton->setText(QApplication::translate("simulateForm", "Add", nullptr));
        label->setText(QApplication::translate("simulateForm", "Add Event:", nullptr));
        label_2->setText(QApplication::translate("simulateForm", "Seed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simulateForm: public Ui_simulateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATEFORM_H
