/********************************************************************************
** Form generated from reading UI file 'removeForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEFORM_H
#define UI_REMOVEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_removeForm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *removeForm)
    {
        if (removeForm->objectName().isEmpty())
            removeForm->setObjectName(QStringLiteral("removeForm"));
        removeForm->resize(360, 70);
        buttonBox = new QDialogButtonBox(removeForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(270, 10, 81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(removeForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 81, 20));
        comboBox = new QComboBox(removeForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 20, 161, 22));

        retranslateUi(removeForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), removeForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), removeForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(removeForm);
    } // setupUi

    void retranslateUi(QDialog *removeForm)
    {
        removeForm->setWindowTitle(QApplication::translate("removeForm", "Remove Event", nullptr));
        label->setText(QApplication::translate("removeForm", "Remove Event:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removeForm: public Ui_removeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEFORM_H
