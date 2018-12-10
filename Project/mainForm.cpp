#include "mainForm.h"
#include "addForm.h"
#include "removeForm.h"
#include "simulateForm.h"
#include "randomEvents.h"
#include "dieForm.h"
#include <QMessageBox>
#include <QString>
#include <QtCharts/QSplineSeries>

mainForm::mainForm() {
    widget.setupUi(this);
}

mainForm::~mainForm() {
}

/**
 *  @brief  Add a "list" event using the %addForm.
 */
void mainForm::on_actionAdd_List_triggered() {
    addForm f;
    if (f.exec()) {
        eventHasBeenAdded = true;
        RandomEvent event(f.getEventName(), f.getColumnList(0), f.getProbabilities());
        events.push_back(event);
    }
}

/**
 *  @brief  Add a "die" event using the %dieForm.
 */
void mainForm::on_actionAdd_Die_triggered() {
    dieForm f;
    if (f.exec()) {
        eventHasBeenAdded = true;
        RandomEvent event(f.getSides());
        events.push_back(event);
    }
}

/**
 *  @brief  Remove an event using the %removeForm.
 */
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

/**
 *  @brief  Simulate events using the %simulateForm and output the simulation results.
 */
void mainForm::on_actionSimulate_triggered() {
    if (events.size()) {
        simulateForm f(&events);
        if (f.exec()) {
            /* Clear the log and the statistics display. */
            widget.resultInfo->clear();
            disconnect(widget.eventID, SIGNAL(currentIndexChanged(int)), this, SLOT(on_eventID_currentIndexChanged(int)));
            widget.eventID->clear();
            connect(widget.eventID, SIGNAL(currentIndexChanged(int)), this, SLOT(on_eventID_currentIndexChanged(int)));
            /* Save the simulated events and the simulation results. */
            simulated_events = f.simulatedEvents();
            vector <int> amounts = f.simulatedEventAmounts();
            results = simulate(simulated_events, amounts, f.seedPresent(), f.seed());
            /* Add the simulation results to the log. */
            widget.resultInfo->appendPlainText("Seed: " + QString::number(results[results.size() - 1][0]) + "\n");
            for (int i = 0; i < results.size() - 1; i++) {
                widget.resultInfo->appendPlainText("Simulation " + QString::number(i + 1));
                for (int j = 0; j < results[i].size(); j++) {
                    widget.resultInfo->appendPlainText("Result of " + simulated_events[i].eventName() + ": " + simulated_events[i].resultName(results[i][j]));
                }
                widget.resultInfo->appendPlainText("");
            }
            widget.resultInfo->appendPlainText("");
            /**
             *  Add the simulated events to the statistics display.
             *  The first event should display automatically.
             */
            for (int i = 0; i < simulated_events.size(); i++) {
                widget.eventID->addItem(QString::number(i + 1) + ": " + simulated_events[i].eventName());
            }
        }
    } else {
        errNothingToSimulate();
    }
}

/**
 *  @brief  Show the respective statistics for the chosen event.
 */
void mainForm::on_eventID_currentIndexChanged(int index) {
    showStats(index);
    showChart(index);
}

/**
 *  @brief  Shows an error message telling there are no events present.
 * 
 *  Show this error message if there are no events present
 *  and a form that requires events to be present is called.
 */
void mainForm::errNothingToSimulate() {
    if (eventHasBeenAdded) {
        QMessageBox msg(QMessageBox::NoIcon, " ", "BUT THERE IS NOTHING LEFT.", QMessageBox::Yes);
        msg.exec();
    } else {
        QMessageBox msg(QMessageBox::NoIcon, " ", "BUT THERE IS NOWHERE TO START FROM.", QMessageBox::Yes);
        msg.exec();
    }
}

/**
 *  @brief  Shows statistics table for the chosen random event.
 *  @param  event_id  The simulated event index.
 */
void mainForm::showStats(int event_id) {
    if (event_id < simulated_events.size()) {
        widget.probabilityTable->setRowCount(simulated_events[event_id].resultAmount());
    }
    for (int i = 0; i < widget.probabilityTable->rowCount(); i++) {
        QTableWidgetItem *name = new QTableWidgetItem(simulated_events[event_id].resultName(i));
        name->setFlags(name->flags() & ~Qt::ItemIsEditable);
        widget.probabilityTable->setItem(i, 0, name);
        
        QTableWidgetItem *expected = new QTableWidgetItem(QString::number(simulated_events[event_id].probability(i)));
        expected->setFlags(name->flags() & ~Qt::ItemIsEditable);
        widget.probabilityTable->setItem(i, 1, expected);
        
        QTableWidgetItem *actual = new QTableWidgetItem(QString::number(experimentalProbability(event_id, i)));
        actual->setFlags(name->flags() & ~Qt::ItemIsEditable);
        widget.probabilityTable->setItem(i, 2, actual);
        
        QTableWidgetItem *difference = new QTableWidgetItem(QString::number(experimentalProbability(event_id, i) - simulated_events[event_id].probability(i)));
        difference->setFlags(name->flags() & ~Qt::ItemIsEditable);
        widget.probabilityTable->setItem(i, 3, difference);
    }
}

/**
 *  @brief  Computes probability of an event result based on experimental data.
 *  @param  event_id  The simulated event index.
 *  @param  result_id  The event result index.
 */
double mainForm::experimentalProbability(int event_id, int result_id) {
    double probability = 0;
    if (event_id < simulated_events.size()) {
        if (result_id < simulated_events[event_id].resultAmount()) {
            for (int i = 0; i < results[event_id].size(); i++) {
                if (result_id == results[event_id][i]) {
                    probability++;
                }
            }
            if (results[event_id].size()) {
                probability /= results[event_id].size();
            }
        }
    }
    return probability;
}

/**
 *  @brief  Shows probability chart for the chosen random event.
 *  @param  event_id  The simulated event index.
 */
void mainForm::showChart(int event_id) {
    if (event_id < simulated_events.size()) {
        QSplineSeries* expected = new QSplineSeries();
        QSplineSeries* actual = new QSplineSeries();
        
        expected->setName("Expected");
        actual->setName("Actual");
        
        expected->append(0, 0);
        actual->append(0, 0);
        
        for (int i = 0; i < simulated_events[event_id].resultAmount(); i++) {
            expected->append(i + 1, simulated_events[event_id].probability(i));
            actual->append(i + 1, experimentalProbability(event_id, i));
        }
        
        expected->append(simulated_events[event_id].resultAmount() + 1, 0);
        actual->append(simulated_events[event_id].resultAmount() + 1, 0);
        
        widget.probabilityChart->chart()->removeAllSeries();
        widget.probabilityChart->chart()->setTitle("Probability distribution");
        widget.probabilityChart->chart()->addSeries(expected);
        widget.probabilityChart->chart()->addSeries(actual);
        widget.probabilityChart->chart()->createDefaultAxes();
        
        double maxProbability = 0;
        for (int i = 0; i < simulated_events[event_id].resultAmount(); i++) {
            if (maxProbability < simulated_events[event_id].probability(i)) {
                maxProbability =  simulated_events[event_id].probability(i);
            }
        }
        
        widget.probabilityChart->chart()->axisX()->setVisible(false);
        widget.probabilityChart->chart()->axisX()->setMax(simulated_events[event_id].resultAmount() + 1);
        widget.probabilityChart->chart()->axisY()->setMax(std::min((double)1, maxProbability * 2));
        
        widget.probabilityChart->chart()->legend()->setVisible(true);
        widget.probabilityChart->chart()->legend()->setAlignment(Qt::AlignBottom);
    }
}