/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "QtCharts\QtCharts"

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QAction *actionSimulate;
    QAction *actionRemove_Random_Event;
    QAction *actionAdd_List;
    QAction *actionAdd_Die;
    QAction *actionAdd_No_repeat_List;
    QWidget *centralwidget;
    QPlainTextEdit *resultInfo;
    QTableWidget *probabilityTable;
    QComboBox *eventID;
    QLabel *labelEventID;
    QChartView *probabilityChart;
    QMenuBar *menubar;
    QMenu *menuEvents;
    QMenu *menuAdd_Random_Event;
    QMenu *menuSimulation;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QStringLiteral("mainForm"));
        mainForm->resize(800, 600);
        actionSimulate = new QAction(mainForm);
        actionSimulate->setObjectName(QStringLiteral("actionSimulate"));
        actionRemove_Random_Event = new QAction(mainForm);
        actionRemove_Random_Event->setObjectName(QStringLiteral("actionRemove_Random_Event"));
        actionAdd_List = new QAction(mainForm);
        actionAdd_List->setObjectName(QStringLiteral("actionAdd_List"));
        actionAdd_Die = new QAction(mainForm);
        actionAdd_Die->setObjectName(QStringLiteral("actionAdd_Die"));
        actionAdd_No_repeat_List = new QAction(mainForm);
        actionAdd_No_repeat_List->setObjectName(QStringLiteral("actionAdd_No_repeat_List"));
        centralwidget = new QWidget(mainForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        resultInfo = new QPlainTextEdit(centralwidget);
        resultInfo->setObjectName(QStringLiteral("resultInfo"));
        resultInfo->setGeometry(QRect(10, 10, 371, 551));
        resultInfo->setReadOnly(true);
        probabilityTable = new QTableWidget(centralwidget);
        if (probabilityTable->columnCount() < 4)
            probabilityTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        probabilityTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        probabilityTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        probabilityTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        probabilityTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        probabilityTable->setObjectName(QStringLiteral("probabilityTable"));
        probabilityTable->setGeometry(QRect(390, 40, 401, 261));
        probabilityTable->horizontalHeader()->setDefaultSectionSize(90);
        eventID = new QComboBox(centralwidget);
        eventID->setObjectName(QStringLiteral("eventID"));
        eventID->setGeometry(QRect(540, 10, 191, 22));
        labelEventID = new QLabel(centralwidget);
        labelEventID->setObjectName(QStringLiteral("labelEventID"));
        labelEventID->setGeometry(QRect(450, 10, 81, 21));
        probabilityChart = new QChartView(centralwidget);
        probabilityChart->setObjectName(QStringLiteral("probabilityChart"));
        probabilityChart->setGeometry(QRect(390, 310, 401, 251));
        mainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuEvents = new QMenu(menubar);
        menuEvents->setObjectName(QStringLiteral("menuEvents"));
        menuAdd_Random_Event = new QMenu(menuEvents);
        menuAdd_Random_Event->setObjectName(QStringLiteral("menuAdd_Random_Event"));
        menuSimulation = new QMenu(menubar);
        menuSimulation->setObjectName(QStringLiteral("menuSimulation"));
        mainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(mainForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainForm->setStatusBar(statusbar);

        menubar->addAction(menuEvents->menuAction());
        menubar->addAction(menuSimulation->menuAction());
        menuEvents->addAction(menuAdd_Random_Event->menuAction());
        menuEvents->addAction(actionRemove_Random_Event);
        menuAdd_Random_Event->addAction(actionAdd_List);
        menuAdd_Random_Event->addAction(actionAdd_Die);
        menuSimulation->addAction(actionSimulate);

        retranslateUi(mainForm);

        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QMainWindow *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "Random Event Simulation", nullptr));
        actionSimulate->setText(QApplication::translate("mainForm", "Simulate...", nullptr));
        actionRemove_Random_Event->setText(QApplication::translate("mainForm", "Remove Random Event...", nullptr));
        actionAdd_List->setText(QApplication::translate("mainForm", "Add List...", nullptr));
        actionAdd_Die->setText(QApplication::translate("mainForm", "Add Die...", nullptr));
        actionAdd_No_repeat_List->setText(QApplication::translate("mainForm", "Add No-repeat List...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = probabilityTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mainForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = probabilityTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mainForm", "Expected", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = probabilityTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mainForm", "Actual", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = probabilityTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("mainForm", "Difference", nullptr));
        labelEventID->setText(QApplication::translate("mainForm", "Show stats for:", nullptr));
        menuEvents->setTitle(QApplication::translate("mainForm", "Events", nullptr));
        menuAdd_Random_Event->setTitle(QApplication::translate("mainForm", "Add Random Event", nullptr));
        menuSimulation->setTitle(QApplication::translate("mainForm", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
