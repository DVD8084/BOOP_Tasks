#include "addForm.h"

using std::vector;

/**
 *  @brief  Creates a default %addForm.
 */
addForm::addForm() {
    widget.setupUi(this);
}

addForm::~addForm() {
}

/**
 *  @brief  Check if the event name is present.
 * 
 *  If the event name is empty, the "Ok" button is disabled.
 */
void addForm::on_name_textChanged(QString text) {
    if (text.isEmpty()) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

/**
 *  @brief  Update the outcome table according to the new amount of event outcomes.
 */
void addForm::on_resultAmount_valueChanged(int val) {
    if (widget.results->rowCount() < val) {
        //Add default entries for all newly created outcomes.
        for (int i = widget.results->rowCount(); i < val; i++) {
            widget.results->setRowCount(i + 1);
            if (!widget.results->item(i, 0)) {
                QTableWidgetItem *name = new QTableWidgetItem("Item " + QString::number(i + 1)); //default name
                widget.results->setItem(i, 0, name);
                QTableWidgetItem *prob = new QTableWidgetItem("1"); //default probability
                widget.results->setItem(i, 1, prob);
            }
        }
    } else {
        //Remove old entries.
        widget.results->setRowCount(val);
    }
}

/**
 *  @brief  Check if all table entries are valid.
 * 
 *  If either any event name is empty or any probability
 *  is less than zero, the "Ok" button is disabled.
 */
void addForm::on_results_cellChanged(int row, int col) {
    for (int i = 0; i < widget.results->rowCount(); i++) {
        if (col) {
            //Probability check, should be a positive double.
            bool ok = false;
            double value = 0;
            value = widget.results->item(i, col)->text().toDouble(&ok);
            if (!ok || value <= 0) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        } else {
            //Outcome name check, should not be empty.
            QString value = widget.results->item(i, col)->text();
            if (value.isEmpty()) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        }
    }
}

/**
 *  @brief  Returns the name of the "list" event.
 */
QString addForm::getEventName() {
    return widget.name->text();
}

/**
 *  @brief  Returns string data from a table column as a QStringList.
 *  @param  col  The column index.
 */
QStringList addForm::getColumnList(int col) {
    QStringList names;
    for (int i = 0; i < widget.results->rowCount(); i++) {
        names << widget.results->item(i, col)->text();
    }
    return names;
}

/**
 *  @brief  Returns the outcome probabilities as a vector<double>.
 */
vector <double> addForm::getProbabilities() {
    QStringList list = addForm::getColumnList(1);
    vector <double> probabilities;
    for (int i = 0; i < list.size(); i++) {
        probabilities.push_back(list[i].toDouble());
    }
    return probabilities;
}