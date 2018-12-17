#include "randomEvents.h"

/**
 *  @brief  Internally used to make the sum of all probabilities equal to 1
 *  when creating an event with an uneven distribution.
 */
void RandomEvent::normalize() {
    double probabilities_sum = 0;
    for (int i = 0; i < probabilities.size(); i++) {
        if (probabilities[i] < 0) {
            probabilities[i] = 0;
        }
    }
    for (int i = 0; i < probabilities.size(); i++) {
        probabilities_sum += probabilities[i];
    }
    if (probabilities_sum) {
        for (int i = 0; i < probabilities.size(); i++) {
            probabilities[i] /= probabilities_sum;
        }
    }
}

/**
 *  @brief  Creates a "die" event with a fixed amount of sides.
 *  @param  result_amount  The side amount.
 */
RandomEvent::RandomEvent(int result_amount)  {
    probabilities.clear();
    if (result_amount < 1) {
        result_amount = 1;
    }
    this -> result_amount = result_amount;
    this -> event_name = "D" + QString::number(result_amount);
    for (int i = 0; i < result_amount; i++) {
        probabilities.push_back((double)1 / result_amount);
        this -> result_names.append(QString::number(i + 1));
    }
}

/**
 *  @brief  Creates a "die" event with a fixed amount of sides
 *  and a user-supplied probability distribution.
 *  @param  result_amount  The side amount.
 *  @param  probabilities  The probability distribution as a vector<double>.
 */
RandomEvent::RandomEvent(int result_amount, vector<double> probabilities) : RandomEvent(result_amount)  {
    for (int i = 0; i < result_amount; i++) {
        if (i < probabilities.size()) {
            this -> probabilities[i] = probabilities[i];
        }
    }
    normalize();
}

/**
 *  @brief  Creates an event with a user-supplied probability distribution
 *  and names for each possible outcome.
 *  @param  result_names  The names of the outcomes.
 *  @param  probabilities  The probability distribution as a vector<double>.
 */
RandomEvent::RandomEvent(QStringList result_names, vector<double> probabilities) : RandomEvent::RandomEvent((result_names.size() > probabilities.size() ? result_names.size() : probabilities.size()), probabilities) {
    for (int i = 0; i < result_names.size(); i++) {
        this -> result_names[i] = result_names[i];
    }
}

/**
 *  @brief  Creates a named event with a user-supplied probability
 *  distribution and names for each possible outcome.
 *  @param  event_name  The name of the event.
 *  @param  result_names  The names of the outcomes.
 *  @param  probabilities  The probability distribution as a vector<double>.
 */
RandomEvent::RandomEvent(QString event_name, QStringList result_names, vector<double> probabilities) : RandomEvent::RandomEvent(result_names, probabilities) {
    this -> event_name = event_name;
}

/**
 *  @brief  Returns the amount of outcomes.
 */
int RandomEvent::resultAmount() {
    return result_amount;
}

/**
 *  @brief  Returns the event name.
 */
QString RandomEvent::eventName() {
    return event_name;
}

/**
 *  @brief  Returns the name of an outcome.
 *  @param  i  The outcome index.
 */
QString RandomEvent::resultName(int i) {
    if (i >= 0 && i < result_amount) {
        return result_names[i];
    } else {
        return "";
    }
}

/**
 *  @brief  Returns the probability of an outcome.
 *  @param  i  The outcome index.
 */
double RandomEvent::probability(int i) {
    if (i >= 0 && i < result_amount) {
        return probabilities[i];
    } else {
        return 0;
    }
}

/**
 *  @brief  Simulates a group of events.
 *  @param  events  The simulated events, as a vector<RandomEvent>.
 *  @param  amounts  The amount of simulation runs for each event, as a vector<int>.
 *  @param  set_seed  Is this is true, the seed for random number generation
 *                    will be determined by the @a seed value,
 *                    rather than the user's current time.
 *  @param  seed  The seed for random number generation. Defaults to 0.
 *  @return  The outcome indexes and the used seed, as a vector<vector<int>>.
 */
vector <vector <int> > simulate(vector <RandomEvent> events, vector <int> amounts, bool set_seed = false, int seed = 0) {
    vector <vector <int> > results(events.size() + 1);
    if (!set_seed) {
        seed = time(0);
    }
    srand(seed);
    rand();
    for (int i = 0; i < events.size(); i++) {
        for (int j = 0; j < amounts[i]; j++) {
            double random = (double) rand() / RAND_MAX;
            double sum = 0;
            for (int k = 0; k < events[i].resultAmount(); k++) {
                sum += events[i].probability(k);
                if (random < sum || sum >= 1) {
                    results[i].push_back(k);
                    break;
                }
            }
        }
    }
    results[results.size() - 1].push_back(seed);
    return results;
}