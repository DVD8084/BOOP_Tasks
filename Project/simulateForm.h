#ifndef _SIMULATEFORM_H
#define _SIMULATEFORM_H

#include <vector>
#include "randomEvents.h"
#include "ui_simulateForm.h"

using std::vector;

/**
 *  @brief  Used to start a simulation of a group of random events.
 */
class simulateForm : public QDialog {
    Q_OBJECT
public:
    simulateForm();
    simulateForm(vector <RandomEvent>*);
    virtual ~simulateForm();
    
    vector <RandomEvent> simulatedEvents();
    vector <int> simulatedEventAmounts();
    int seed();
    bool seedPresent();
    
private slots:
    void on_addEvent_clicked();
    void on_eventAmounts_cellChanged(int, int);
    void on_seed_textChanged(QString);
    
private:
    Ui::simulateForm widget;
    vector <RandomEvent> *events;
    vector <int> simulated_ids;
};

#endif /* _SIMULATEFORM_H */
