#include "removeForm.h"

using std::vector;

removeForm::removeForm() {
    widget.setupUi(this);
}

removeForm::removeForm(vector <RandomEvent>* events) {
    this->events = events;
    widget.setupUi(this);
    for (int i = 0; i < events->size(); i++) {
        widget.comboBox->addItem(QString::number(i + 1) + ": " + events->at(i).eventName());
    }
}

removeForm::~removeForm() {
}

int removeForm::selectedID() {
    return widget.comboBox->currentIndex();
}