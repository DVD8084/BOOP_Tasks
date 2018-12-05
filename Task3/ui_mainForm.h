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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QAction *actionCompress;
    QAction *actionUnpack;
    QAction *actionExit;
    QAction *actionOpen_File;
    QAction *actionOpen_Folder;
    QAction *actionAbout;
    QWidget *centralwidget;
    QTreeWidget *contents;
    QPlainTextEdit *log;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QStringLiteral("mainForm"));
        mainForm->resize(800, 320);
        actionCompress = new QAction(mainForm);
        actionCompress->setObjectName(QStringLiteral("actionCompress"));
        actionUnpack = new QAction(mainForm);
        actionUnpack->setObjectName(QStringLiteral("actionUnpack"));
        actionExit = new QAction(mainForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen_File = new QAction(mainForm);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionOpen_Folder = new QAction(mainForm);
        actionOpen_Folder->setObjectName(QStringLiteral("actionOpen_Folder"));
        actionAbout = new QAction(mainForm);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralwidget = new QWidget(mainForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        contents = new QTreeWidget(centralwidget);
        contents->setObjectName(QStringLiteral("contents"));
        contents->setGeometry(QRect(20, 20, 361, 241));
        log = new QPlainTextEdit(centralwidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(400, 20, 381, 241));
        mainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        mainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(mainForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        mainForm->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_Folder);
        menuFile->addAction(actionOpen_File);
        menuFile->addSeparator();
        menuFile->addAction(actionCompress);
        menuFile->addAction(actionUnpack);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(mainForm);
        QObject::connect(actionExit, SIGNAL(triggered()), mainForm, SLOT(close()));

        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QMainWindow *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "mainForm", nullptr));
        actionCompress->setText(QApplication::translate("mainForm", "Compress...", nullptr));
        actionUnpack->setText(QApplication::translate("mainForm", "Unpack...", nullptr));
        actionExit->setText(QApplication::translate("mainForm", "Exit", nullptr));
        actionOpen_File->setText(QApplication::translate("mainForm", "Open File...", nullptr));
        actionOpen_Folder->setText(QApplication::translate("mainForm", "Open Folder...", nullptr));
        actionAbout->setText(QApplication::translate("mainForm", "About", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = contents->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("mainForm", "Size", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("mainForm", "Name", nullptr));
        menuFile->setTitle(QApplication::translate("mainForm", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("mainForm", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
