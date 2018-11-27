/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   dieForm.cpp
 * Author: DVD
 *
 * Created on 20 ноября 2018 г., 18:10
 */

#include "dieForm.h"

dieForm::dieForm() {
    widget.setupUi(this);
    widget.lineEdit->setText("2");
}

dieForm::~dieForm() {
}

void dieForm::on_lineEdit_textChanged(QString text) {
    bool ok = false;
    int value = 0;
    value = text.toInt(&ok);
    if (!ok || value < 2 || value > 9999) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

int dieForm::getSides() {
    return widget.lineEdit->text().toInt();
}