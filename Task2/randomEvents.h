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
 *  @brief  Container used to store random events.
 *  
 *  Stores information about the event name and the names and
 *  probabilities of the event outcomes.
 */
class RandomEvent
{
private:
    int result_amount = 1;
    QString event_name;
    QStringList result_names;
    vector <double> probabilities;
    /**
     *  @brief  Internally used to make the sum of all probabilities equal to 1
     *  when creating an event with an uneven distribution.
     */
    void normalize();
    
public:
    
    /**
     *  @brief  Creates a "die" event with a fixed amount of sides.
     *  @param  result_amount  The side amount.
     */
    RandomEvent(int);
    
    /**
     *  @brief  Creates a "die" event with a fixed amount of sides
     *  and a user-supplied probability distribution.
     *  @param  result_amount  The side amount.
     *  @param  probabilities  The probability distribution as a vector<double>.
     */
    RandomEvent(int, vector<double>);
    
    /**
     *  @brief  Creates an event with a user-supplied probability distribution
     *  and names for each possible outcome.
     *  @param  result_names  The names of the outcomes.
     *  @param  probabilities  The probability distribution as a vector<double>.
     */
    RandomEvent(QStringList, vector<double>);
    
    /**
     *  @brief  Creates a named event with a user-supplied probability
     *  distribution and names for each possible outcome.
     *  @param  event_name  The name of the event.
     *  @param  result_names  The names of the outcomes.
     *  @param  probabilities  The probability distribution as a vector<double>.
     */
    RandomEvent(QString, QStringList, vector<double>);
    
    /**
     *  @brief  Returns the amount of outcomes.
     */
    int resultAmount();
    
    /**
     *  @brief  Returns the event name.
     */
    QString eventName();
    
    /**
     *  @brief  Returns the name of an outcome.
     *  @param  i  The outcome index.
     */
    QString resultName(int);
    
    /**
     *  @brief  Returns the probability of an outcome.
     *  @param  i  The outcome index.
     */
    double probability(int);
};


/**
 *  @brief  Simulates a group of events.
 *  @param  events  The simulated events, as a vector<RandomEvent>.
 *  @param  set_seed  Is this is true, the seed for random number generation
 *                    will be determined by the @a seed value,
 *                    rather than the user's current time.
 *  @param  seed  The seed for random number generation. Defaults to 0.
 *  @return  The outcome indexes and the used seed, as a vector<int>.
 */
vector <int> simulate(vector <RandomEvent>, bool, int);

#endif /* RANDOMEVENTS_H */

