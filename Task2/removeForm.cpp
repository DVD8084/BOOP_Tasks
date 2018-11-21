/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   removeForm.cpp
 * Author: DVD
 *
 * Created on 11 ноября 2018 г., 11:42
 */

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