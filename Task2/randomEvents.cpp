#include "randomEvents.h"

void RandomEvent::normalize()
{
    double probabilities_sum = 0;
    for (int i = 0; i < probabilities.size(); i++)
    {
        if (probabilities[i] < 0)
        {
            probabilities[i] = 0;
        }
    }
    for (int i = 0; i < probabilities.size(); i++)
    {
        probabilities_sum += probabilities[i];
    }
    if (probabilities_sum)
    {
        for (int i = 0; i < probabilities.size(); i++)
        {
            probabilities[i] /= probabilities_sum;
        }
    }
}

RandomEvent::RandomEvent(int result_amount) 
{
    probabilities.clear();
    if (result_amount < 1)
    {
        result_amount = 1;
    }
    this -> result_amount = result_amount;
    this -> event_name = "D" + QString::number(result_amount);
    for (int i = 0; i < result_amount; i++)
    {
        probabilities.push_back((double)1 / result_amount);
        this -> result_names.append(QString::number(i + 1));
    }
}

RandomEvent::RandomEvent(int result_amount, vector<double> probabilities) : RandomEvent(result_amount) 
{
    for (int i = 0; i < result_amount; i++)
    {
        if (i < probabilities.size())
        {
            this -> probabilities[i] = probabilities[i];
        }
    }
    normalize();
}

RandomEvent::RandomEvent(QStringList result_names, vector<double> probabilities) : RandomEvent::RandomEvent((result_names.size() > probabilities.size() ? result_names.size() : probabilities.size()), probabilities)
{
    for (int i = 0; i < result_names.size(); i++)
    {
        this -> result_names[i] = result_names[i];
    }
}

RandomEvent::RandomEvent(QString event_name, QStringList result_names, vector<double> probabilities) : RandomEvent::RandomEvent(result_names, probabilities)
{
    this -> event_name = event_name;
}

int RandomEvent::resultAmount()
{
    return result_amount;
}

QString RandomEvent::eventName()
{
    return event_name;
}

QString RandomEvent::resultName(int i)
{
    if (i >= 0 && i < result_amount)
    {
        return result_names[i];
    }
    else
    {
        return "";
    }
}

double RandomEvent::probability(int i)
{
    if (i >= 0 && i < result_amount)
    {
        return probabilities[i];
    }
    else
    {
        return 0;
    }
}

vector <int> simulate(vector <RandomEvent> events, bool set_seed = false, int seed = 0)
{
    vector <int> results(events.size());
    if (!set_seed)
    {
        seed = time(0);
    }
    srand(seed);
    for (int i = 0; i < events.size(); i++)
    {
        double random = (double) rand() / RAND_MAX;
        double sum = 0;
        for (int j = 0; j < events[i].resultAmount(); j++)
        {
            sum += events[i].probability(j);
            if (random < sum || sum >= 1)
            {
                results[i] = j;
                break;
            }
        }
    }
    results.push_back(seed);
    return results;
}