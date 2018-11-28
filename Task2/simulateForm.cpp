#include "simulateForm.h"

using std::vector;

simulateForm::simulateForm() {
    widget.setupUi(this);
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    widget.tableWidget->setColumnWidth(0, 150);
    widget.tableWidget->horizontalHeader()->setStretchLastSection(true);
}

simulateForm::simulateForm(vector <RandomEvent>* events) : simulateForm::simulateForm() {
    this->events = events;
    for (int i = 0; i < events->size(); i++) {
        widget.comboBox->addItem(QString::number(i + 1) + ": " + events->at(i).eventName());
    }
}

simulateForm::~simulateForm() {
}

void simulateForm::on_pushButton_clicked() {
    simulated_ids.push_back(widget.comboBox->currentIndex());
    int rows = widget.tableWidget->rowCount();
    if (!rows) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    //Add new table entries for the event.
    widget.tableWidget->setRowCount(rows + 1);
    QTableWidgetItem *name = new QTableWidgetItem(events->at(widget.comboBox->currentIndex()).eventName());
    name->setFlags(name->flags() & ~Qt::ItemIsEditable);
    widget.tableWidget->setItem(rows, 0, name);
    QTableWidgetItem *amount = new QTableWidgetItem("1");
    widget.tableWidget->setItem(rows, 1, amount);
}


void simulateForm::on_tableWidget_cellChanged(int row, int col) {
    //Check if all table entries are valid.
    for (int i = 0; i < widget.tableWidget->rowCount(); i++) {
        if (col) {
            //Check if the amount of events is a positive integer.
            bool ok = false;
            int value = 0;
            value = widget.tableWidget->item(i, col)->text().toInt(&ok);
            if (!ok || value <= 0) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        }
    }
}

void simulateForm::on_lineEdit_textChanged(QString text) {
    //Check if the seed is an integer.
    bool ok = false;
    text.toInt(&ok);
    if (!ok) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

vector <RandomEvent> simulateForm::simulatedEvents() {
    //Construct the event list from event IDs and event amounts.
    vector <RandomEvent> simulated_events;
    for (int i = 0; i < widget.tableWidget->rowCount(); i++) {
        for (int j = 0; j < widget.tableWidget->item(i, 1)->text().toInt(); j++) {
            simulated_events.push_back(events->at(simulated_ids[i]));
        }
    }
    return simulated_events;
}

int simulateForm::seed() {
    return widget.lineEdit->text().toInt();
}

bool simulateForm::seedPresent() {
    return !widget.lineEdit->text().isEmpty();
}