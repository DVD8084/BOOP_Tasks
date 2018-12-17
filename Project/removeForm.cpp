#include "removeForm.h"

using std::vector;

/**
 *  @brief  Creates an empty %removeForm.
 */
removeForm::removeForm() {
    widget.setupUi(this);
}

/**
 *  @brief  Creates a %removeForm with a specific set of events.
 *  @param  events  The set of events, as a vector<RandomEvent>.
 */
removeForm::removeForm(vector <RandomEvent>* events) {
    this->events = events;
    widget.setupUi(this);
    for (int i = 0; i < events->size(); i++) {
        widget.eventID->addItem(QString::number(i + 1) + ": " + events->at(i).eventName());
    }
}

removeForm::~removeForm() {
}

/**
 *  @brief  Returns the index of the event to remove.
 */
int removeForm::selectedID() {
    return widget.eventID->currentIndex();
}