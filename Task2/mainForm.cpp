/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main_form.cpp
 * Author: DVD
 *
 * Created on 24 октября 2018 г., 15:23
 */

#include "mainForm.h"
#include "addForm.h"
#include "removeForm.h"
#include "simulateForm.h"
#include "randomEvents.h"
#include "dieForm.h"
#include <QMessageBox>

mainForm::mainForm() {
    widget.setupUi(this);
}

mainForm::~mainForm() {
}

void mainForm::on_actionAdd_List_triggered() {
    addForm f;
    if (f.exec()) {
        eventHasBeenAdded = true;
        RandomEvent event(f.getEventName(), f.getColumnList(0), f.getProbabilities());
        events.push_back(event);
    }
}

void mainForm::on_actionAdd_Die_triggered() {
    dieForm f;
    if (f.exec()) {
        eventHasBeenAdded = true;
        RandomEvent event(f.getSides());
        events.push_back(event);
    }
}

void mainForm::on_actionRemove_Random_Event_triggered() {
    if (events.size()) {
        removeForm f(&events);
        if (f.exec()) {
            events.erase(events.begin() + f.selectedID());
        }
    } else {
        errNothingToSimulate();
    }
}

void mainForm::on_actionSimulate_triggered() {
    if (events.size()) {
        simulateForm f(&events);
        if (f.exec()) {
            vector <RandomEvent> simulated_events = f.simulatedEvents();
            vector <int> results = simulate(simulated_events, f.seedPresent(), f.seed());
            widget.plainTextEdit->appendPlainText("Seed: " + QString::number(results[results.size() - 1]));
            for (int i = 0; i < results.size() - 1; i++) {
                widget.plainTextEdit->appendPlainText("Result of " + simulated_events[i].eventName() + ": " + simulated_events[i].resultName(results[i]));
            }
            widget.plainTextEdit->appendPlainText("");
        }
    } else {
        errNothingToSimulate();
    }
}

void mainForm::errNothingToSimulate() {
    if (eventHasBeenAdded) {
        QMessageBox msg(QMessageBox::NoIcon, " ", "BUT THERE IS NOTHING LEFT.", QMessageBox::Yes);
        msg.exec();
    } else {
        QMessageBox msg(QMessageBox::NoIcon, " ", "BUT THERE IS NOWHERE TO START FROM.", QMessageBox::Yes);
        msg.exec();
    }
}