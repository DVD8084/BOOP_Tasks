/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   simulateForm.h
 * Author: DVD
 *
 * Created on 13 ноября 2018 г., 21:27
 */

#ifndef _SIMULATEFORM_H
#define _SIMULATEFORM_H

#include <vector>
#include "randomEvents.h"
#include "ui_simulateForm.h"

using std::vector;

class simulateForm : public QDialog {
    Q_OBJECT
public:
    simulateForm();
    simulateForm(vector <RandomEvent>*);
    virtual ~simulateForm();
    vector <RandomEvent> simulatedEvents();
    int seed();
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
