#include "dieForm.h"

dieForm::dieForm() {
    widget.setupUi(this);
    widget.lineEdit->setText("2");
}

dieForm::~dieForm() {
}

void dieForm::on_lineEdit_textChanged(QString text) {
    //Check if the amount of sides is more than 1 and less than 10000.
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