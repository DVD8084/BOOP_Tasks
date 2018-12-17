#include "simulateForm.h"

using std::vector;

/**
 *  @brief  Creates an empty %simulateForm.
 */
simulateForm::simulateForm() {
    widget.setupUi(this);
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    widget.eventAmounts->setColumnWidth(0, 150);
    widget.eventAmounts->horizontalHeader()->setStretchLastSection(true);
}

/**
 *  @brief  Creates a %simulateForm with a specific set of events.
 *  @param  events  The set of events, as a vector<RandomEvent>.
 */
simulateForm::simulateForm(vector <RandomEvent>* events) : simulateForm::simulateForm() {
    this->events = events;
    for (int i = 0; i < events->size(); i++) {
        widget.eventID->addItem(QString::number(i + 1) + ": " + events->at(i).eventName());
    }
}

simulateForm::~simulateForm() {
}

/**
 *  @brief  Add the currently chosen event to the simulated events table.
 */
void simulateForm::on_addEvent_clicked() {
    /* Add event to the simulated events list. */
    simulated_ids.push_back(widget.eventID->currentIndex());
    int rows = widget.eventAmounts->rowCount();
    if (!rows) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    /* Add new table entries for the event. */
    widget.eventAmounts->setRowCount(rows + 1);
    QTableWidgetItem *name = new QTableWidgetItem(events->at(widget.eventID->currentIndex()).eventName());
    name->setFlags(name->flags() & ~Qt::ItemIsEditable);
    widget.eventAmounts->setItem(rows, 0, name);
    QTableWidgetItem *amount = new QTableWidgetItem("1");
    widget.eventAmounts->setItem(rows, 1, amount);
}

/**
 *  @brief  Check if all table entries are valid.
 * 
 *  If any event amount isn't a positive integer, the "Ok" button is disabled.
 */
void simulateForm::on_eventAmounts_cellChanged(int row, int col) {
    for (int i = 0; i < widget.eventAmounts->rowCount(); i++) {
        if (col) {
            /* Check if the amount of events is a positive integer. */
            bool ok = false;
            int value = 0;
            value = widget.eventAmounts->item(i, col)->text().toInt(&ok);
            if (!ok || value <= 0) {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
                break;
            } else {
                widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        }
    }
}

/**
 *  @brief  Check if the seed is an integer.
 * 
 *  If the seed isn't an integer, the "Ok" button is disabled.
 */
void simulateForm::on_seed_textChanged(QString text) {
    bool ok = false;
    text.toInt(&ok);
    if (!ok) {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

/**
 *  @brief  Returns the events to simulate.
 */
vector <RandomEvent> simulateForm::simulatedEvents() {
    /* Construct the event vector from event IDs. */
    vector <RandomEvent> simulated_events;
    for (int i = 0; i < widget.eventAmounts->rowCount(); i++) {
        simulated_events.push_back(events->at(simulated_ids[i]));
    }
    return simulated_events;
}

/**
 *  @brief  Returns the amounts of events to simulate.
 */
vector <int> simulateForm::simulatedEventAmounts() {
    /* Construct the amount vector from event amounts. */
    vector <int> amounts;
    for (int i = 0; i < widget.eventAmounts->rowCount(); i++) {
        amounts.push_back(widget.eventAmounts->item(i, 1)->text().toInt());
    }
    return amounts;
}

/**
 *  @brief  Returns the simulation seed.
 */
int simulateForm::seed() {
    return widget.seed->text().toInt();
}

/**
 *  @brief  Returns true if the seed has been input by user.
 */
bool simulateForm::seedPresent() {
    return !widget.seed->text().isEmpty();
}