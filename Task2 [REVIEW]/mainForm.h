/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main_form.h
 * Author: DVD
 *
 * Created on 24 октября 2018 г., 15:23
 */

#ifndef _MAINFORM_H
#define _MAINFORM_H

#include <vector>
#include "randomEvents.h"
#include "ui_mainForm.h"

using std::vector;

class mainForm : public QMainWindow {
    Q_OBJECT
public:
    mainForm();
    virtual ~mainForm();
    
private slots:        
    void on_actionAdd_List_triggered();
    void on_actionAdd_Die_triggered();
    void on_actionRemove_Random_Event_triggered();
    void on_actionSimulate_triggered();
    
private:
    Ui::mainForm widget;
    bool eventHasBeenAdded = false;
    vector <RandomEvent> events;
    void errNothingToSimulate();
};

#endif /* _MAINFORM_H */
