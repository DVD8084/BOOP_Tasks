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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
    QPlainTextEdit *plainTextEdit;
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
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 10, 781, 551));
        plainTextEdit->setReadOnly(true);
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
