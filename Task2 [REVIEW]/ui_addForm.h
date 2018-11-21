/********************************************************************************
** Form generated from reading UI file 'addForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFORM_H
#define UI_ADDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_addForm
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *addForm)
    {
        if (addForm->objectName().isEmpty())
            addForm->setObjectName(QStringLiteral("addForm"));
        addForm->resize(342, 296);
        buttonBox = new QDialogButtonBox(addForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(200, 10, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(addForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 10, 42, 22));
        spinBox->setMinimum(1);
        tableWidget = new QTableWidget(addForm);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 80, 301, 192));
        tableWidget->setLineWidth(1);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(2);
        label = new QLabel(addForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 61, 21));
        lineEdit = new QLineEdit(addForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 101, 20));
        label_2 = new QLabel(addForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 61, 21));

        retranslateUi(addForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), addForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(addForm);
    } // setupUi

    void retranslateUi(QDialog *addForm)
    {
        addForm->setWindowTitle(QApplication::translate("addForm", "Add List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addForm", "Mathematical expectation", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("addForm", "Item 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("addForm", "1", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("addForm", "Item Count:", nullptr));
        lineEdit->setText(QApplication::translate("addForm", "List", nullptr));
        label_2->setText(QApplication::translate("addForm", "List Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addForm: public Ui_addForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFORM_H
