/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dieForm.h
 * Author: DVD
 *
 * Created on 20 ноября 2018 г., 18:10
 */

#ifndef _DIEFORM_H
#define _DIEFORM_H

#include <QPushButton>
#include "ui_dieForm.h"

class dieForm : public QDialog {
    Q_OBJECT
public:
    dieForm();
    virtual ~dieForm();
    int getSides();

private slots:
    void on_lineEdit_textChanged(QString);

private:
    Ui::dieForm widget;
};

#endif /* _DIEFORM_H */
