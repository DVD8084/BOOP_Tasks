/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   addForm.h
 * Author: DVD
 *
 * Created on 24 октября 2018 г., 15:56
 */

#ifndef _ADDFORM_H
#define _ADDFORM_H

#include <vector>
#include <QPushButton>
#include "ui_addForm.h"

using std::vector;

class addForm : public QDialog {
    Q_OBJECT
public:
    addForm();
    virtual ~addForm();
    QString getEventName();
    QStringList getColumnList(int);
    vector <double> getProbabilities();

private slots:
    void on_lineEdit_textChanged(QString);
    void on_spinBox_valueChanged(int);
    void on_tableWidget_cellChanged(int, int);
    
private:
    Ui::addForm widget;
    
};

#endif /* _ADDFORM_H */
