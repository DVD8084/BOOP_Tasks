/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   removeForm.h
 * Author: DVD
 *
 * Created on 11 ноября 2018 г., 11:42
 */

#ifndef _REMOVEFORM_H
#define _REMOVEFORM_H

#include <vector>
#include "ui_removeForm.h"
#include "randomEvents.h"

using std::vector;

class removeForm : public QDialog {
    Q_OBJECT
public:
    removeForm();
    removeForm(vector <RandomEvent>*);
    virtual ~removeForm();
    int selectedID();
    
private:
    Ui::removeForm widget;
    vector <RandomEvent> *events;
};

#endif /* _REMOVEFORM_H */
