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
    QTableWidget *eventAmounts;
    QComboBox *eventID;
    QPushButton *addEvent;
    QLabel *labelEventID;
    QLineEdit *seed;
    QLabel *labelSeed;

    void setupUi(QDialog *simulateForm)
    {
        if (simulateForm->objectName().isEmpty())
            simulateForm->setObjectName(QStringLiteral("simulateForm"));
        simulateForm->resize(340, 270);
        buttonBox = new QDialogButtonBox(simulateForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 230, 161, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        eventAmounts = new QTableWidget(simulateForm);
        if (eventAmounts->columnCount() < 2)
            eventAmounts->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        eventAmounts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        eventAmounts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        eventAmounts->setObjectName(QStringLiteral("eventAmounts"));
        eventAmounts->setGeometry(QRect(20, 40, 301, 181));
        eventAmounts->setRowCount(0);
        eventID = new QComboBox(simulateForm);
        eventID->setObjectName(QStringLiteral("eventID"));
        eventID->setGeometry(QRect(110, 10, 131, 21));
        addEvent = new QPushButton(simulateForm);
        addEvent->setObjectName(QStringLiteral("addEvent"));
        addEvent->setGeometry(QRect(260, 10, 41, 23));
        labelEventID = new QLabel(simulateForm);
        labelEventID->setObjectName(QStringLiteral("labelEventID"));
        labelEventID->setGeometry(QRect(40, 10, 61, 21));
        seed = new QLineEdit(simulateForm);
        seed->setObjectName(QStringLiteral("seed"));
        seed->setGeometry(QRect(60, 240, 81, 21));
        labelSeed = new QLabel(simulateForm);
        labelSeed->setObjectName(QStringLiteral("labelSeed"));
        labelSeed->setGeometry(QRect(20, 240, 31, 16));

        retranslateUi(simulateForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), simulateForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), simulateForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(simulateForm);
    } // setupUi

    void retranslateUi(QDialog *simulateForm)
    {
        simulateForm->setWindowTitle(QApplication::translate("simulateForm", "Simulation Options", nullptr));
        QTableWidgetItem *___qtablewidgetitem = eventAmounts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("simulateForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = eventAmounts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("simulateForm", "Amount", nullptr));
        addEvent->setText(QApplication::translate("simulateForm", "Add", nullptr));
        labelEventID->setText(QApplication::translate("simulateForm", "Add Event:", nullptr));
        seed->setText(QString());
        labelSeed->setText(QApplication::translate("simulateForm", "Seed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simulateForm: public Ui_simulateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATEFORM_H
