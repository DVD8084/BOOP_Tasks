/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   randomEvents.h
 * Author: DVD
 *
 * Created on 10 ноября 2018 г., 15:27
 */

#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <QStringList>

using std::vector;
using std::cout;

class RandomEvent
{
private:
    int result_amount = 1;
    QString event_name;
    QStringList result_names;
    vector <double> probabilities;
    void normalize();
public:   
    RandomEvent(int);
    RandomEvent(int, vector<double>);
    RandomEvent(QStringList, vector<double>);
    RandomEvent(QString, QStringList, vector<double>);
    int resultAmount();
    QString eventName();
    QString resultName(int);
    double probability(int);
};

vector <int> simulate(vector <RandomEvent>, bool, int);

#endif /* RANDOMEVENTS_H */

