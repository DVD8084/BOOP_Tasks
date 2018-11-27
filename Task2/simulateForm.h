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
    
    /**
     *  @brief  Creates an empty %simulateForm.
     */
    simulateForm();
    
    /**
     *  @brief  Creates a %simulateForm with a specific set of events.
     *  @param  events  The set of events, as a vector<RandomEvent>.
     */
    simulateForm(vector <RandomEvent>*);
    
    virtual ~simulateForm();
    
    /**
     *  @brief  Returns the events to simulate.
     */
    vector <RandomEvent> simulatedEvents();
    
    /**
     *  @brief  Returns the simulation seed.
     */
    int seed();
    
    /**
     *  @brief  Returns true if the seed has been input by user.
     */
    bool seedPresent();
    
private slots:
    void on_pushButton_clicked();
    void on_tableWidget_cellChanged(int, int);
    void on_lineEdit_textChanged(QString);
    
private:
    Ui::simulateForm widget;
    vector <RandomEvent> *events;
    vector <int> simulated_ids;
};

#endif /* _SIMULATEFORM_H */
