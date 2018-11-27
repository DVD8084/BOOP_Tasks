#include "addForm.h"

using std::vector;

addForm::addForm() {
    widget.setupUi(this);
    widget.tableWidget->horizontalHeader()->setStretchLastSection(true);
}

addForm::~addForm() {
}

void addForm::on_lineEdit_textChanged(QString text) {
    //Check if the event name is present.
    if (text.isEmpty()) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void addForm::on_spinBox_valueChanged(int val) {
    if (widget.tableWidget->rowCount() < val) {
        //Add default entries for all newly created outcomes.
        for (int i = widget.tableWidget->rowCount(); i < val; i++) {
            widget.tableWidget->setRowCount(i + 1);
            if (!widget.tableWidget->item(i, 0)) {
                QTableWidgetItem *name = new QTableWidgetItem("Item " + QString::number(i + 1)); //default name
                widget.tableWidget->setItem(i, 0, name);
                QTableWidgetItem *prob = new QTableWidgetItem("1"); //default probability
                widget.tableWidget->setItem(i, 1, prob);
            }
        }
    } else {
        //Remove old entries.
        widget.tableWidget->setRowCount(val);
    }
}

void addForm::on_tableWidget_cellChanged(int row, int col) {
    //Check if all table entries are valid.
    for (int i = 0; i < widget.tableWidget->rowCount(); i++) {
        if (col) {
            //Probability check, should be a positive double.
            bool ok = false;
            double value = 0;
            value = widget.tableWidget->item(i, col)->text().toDouble(&ok);
            if (!ok || value <= 0) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        } else {
            //Outcome name check, should not be empty.
            QString value = widget.tableWidget->item(i, col)->text();
            if (value.isEmpty()) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        }
    }
}

QString addForm::getEventName() {
    return widget.lineEdit->text();
}

QStringList addForm::getColumnList(int col) {
    QStringList names;
    for (int i = 0; i < widget.tableWidget->rowCount(); i++) {
        names << widget.tableWidget->item(i, col)->text();
    }
    return names;
}

vector <double> addForm::getProbabilities() {
    QStringList list = addForm::getColumnList(1);
    vector <double> probabilities;
    for (int i = 0; i < list.size(); i++) {
        probabilities.push_back(list[i].toDouble());
    }
    return probabilities;
}