/********************************************************************************
** Form generated from reading UI file 'dieForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIEFORM_H
#define UI_DIEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_dieForm
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *sideAmount;
    QLabel *labelAmount;

    void setupUi(QDialog *dieForm)
    {
        if (dieForm->objectName().isEmpty())
            dieForm->setObjectName(QStringLiteral("dieForm"));
        dieForm->resize(200, 90);
        buttonBox = new QDialogButtonBox(dieForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 50, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        sideAmount = new QLineEdit(dieForm);
        sideAmount->setObjectName(QStringLiteral("sideAmount"));
        sideAmount->setGeometry(QRect(90, 20, 61, 20));
        labelAmount = new QLabel(dieForm);
        labelAmount->setObjectName(QStringLiteral("labelAmount"));
        labelAmount->setGeometry(QRect(50, 20, 31, 21));

        retranslateUi(dieForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), dieForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dieForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(dieForm);
    } // setupUi

    void retranslateUi(QDialog *dieForm)
    {
        dieForm->setWindowTitle(QApplication::translate("dieForm", "Add Die", nullptr));
        labelAmount->setText(QApplication::translate("dieForm", "Sides:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dieForm: public Ui_dieForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIEFORM_H
