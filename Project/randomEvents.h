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

/**
 *  @brief  Class used to store random events.
 *  
 *  Stores information about the event name and the names and
 *  probabilities of the event outcomes.
 */
class RandomEvent {
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

vector <vector <int> > simulate(vector <RandomEvent>, vector <int>, bool, int);

#endif /* RANDOMEVENTS_H */

