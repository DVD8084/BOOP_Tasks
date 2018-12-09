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
    QSpinBox *resultAmount;
    QTableWidget *results;
    QLabel *labelAmount;
    QLineEdit *name;
    QLabel *labelName;

    void setupUi(QDialog *addForm)
    {
        if (addForm->objectName().isEmpty())
            addForm->setObjectName(QStringLiteral("addForm"));
        addForm->resize(400, 300);
        buttonBox = new QDialogButtonBox(addForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(250, 10, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        resultAmount = new QSpinBox(addForm);
        resultAmount->setObjectName(QStringLiteral("resultAmount"));
        resultAmount->setGeometry(QRect(160, 10, 42, 22));
        resultAmount->setMinimum(1);
        results = new QTableWidget(addForm);
        if (results->columnCount() < 2)
            results->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        results->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        results->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (results->rowCount() < 1)
            results->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        results->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        results->setItem(0, 1, __qtablewidgetitem3);
        results->setObjectName(QStringLiteral("results"));
        results->setGeometry(QRect(20, 80, 361, 201));
        results->setLineWidth(1);
        results->setRowCount(1);
        results->setColumnCount(2);
        results->horizontalHeader()->setDefaultSectionSize(150);
        labelAmount = new QLabel(addForm);
        labelAmount->setObjectName(QStringLiteral("labelAmount"));
        labelAmount->setGeometry(QRect(80, 10, 61, 21));
        name = new QLineEdit(addForm);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 40, 101, 20));
        labelName = new QLabel(addForm);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setGeometry(QRect(60, 40, 61, 21));

        retranslateUi(addForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), addForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(addForm);
    } // setupUi

    void retranslateUi(QDialog *addForm)
    {
        addForm->setWindowTitle(QApplication::translate("addForm", "Add List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = results->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = results->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addForm", "Mathematical expectation", nullptr));

        const bool __sortingEnabled = results->isSortingEnabled();
        results->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = results->item(0, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("addForm", "Item 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = results->item(0, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("addForm", "1", nullptr));
        results->setSortingEnabled(__sortingEnabled);

        labelAmount->setText(QApplication::translate("addForm", "Item Count:", nullptr));
        name->setText(QApplication::translate("addForm", "List", nullptr));
        labelName->setText(QApplication::translate("addForm", "List Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addForm: public Ui_addForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFORM_H
