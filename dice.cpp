#include "dice.h"

using std::vector;
using std::cout;

void Dice::normalize()
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
Dice::Dice() 
{
    probabilities.clear();
    this -> sides = 2;
    for (int i = 0; i < 2; i++)
    {
        probabilities.push_back(0.5);
    }
}    
Dice::Dice(int sides) 
{
    probabilities.clear();
    if (sides < 1)
    {
        sides = 1;
    }
    this -> sides = sides;
    for (int i = 0; i < sides; i++)
    {
        probabilities.push_back((double)1 / sides);
    }
}
Dice::Dice(int sides, vector<double> probabilities) 
{
    if (sides < 1)
    {
        sides = 1;
    }
    this -> sides = sides;
    for (int i = 0; i < sides; i++)
    {
        if (i < probabilities.size())
        {
            (this -> probabilities).push_back(probabilities[i]);
        }
        else
        {
            probabilities.push_back((double)1 / sides);
        }
    }
    normalize();
}
int Dice::side_amount()
{
    return sides;
}
double Dice::probability(int i)
{
    if (i >= 0 && i < sides)
    {
        return probabilities[i];
    }
    else
    {
        return 0;
    }
}

vector <vector <int> > get_roll_consequences(vector <Dice> dice_set)
{
    vector <vector <int> > roll_consequences;
    int dice_amount = dice_set.size();
    int variant_amount = 1;
    for (int i = 0; i < dice_amount; i++)
    {
        variant_amount *= dice_set[i].side_amount();
    }
    vector <int> consequence (dice_amount, 0);
    for (int i = 0; i < variant_amount; i++)
    {
        roll_consequences.push_back(consequence);
    }
    for (int i = 0; i < variant_amount; i++)
    {
        int result_divisor = variant_amount;
        for (int j = 0; j < dice_amount; j++)
        {
            result_divisor /= dice_set[j].side_amount();
            roll_consequences[i][j] = (i / result_divisor) % dice_set[j].side_amount();
        }
    }
    return roll_consequences;
}

vector <vector <vector <int> > > get_sorted_consequences(vector <Dice> dice_set)
{
    vector <vector <int> > roll_consequences = get_roll_consequences(dice_set);
    int dice_amount = dice_set.size();
    int score_amount = 1;
    for (int i = 0; i < dice_amount; i++)
    {
        score_amount += dice_set[i].side_amount() - 1;
    }
    vector <vector <vector <int> > > sorted_consequences(score_amount);
    for (int i = 0; i < roll_consequences.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < dice_amount; j++)
        {
            sum += roll_consequences[i][j];
        }
        sorted_consequences[sum].push_back(roll_consequences[i]);
    }
    return sorted_consequences;
}

void print_probabilities(vector <Dice> dice_set)
{
    int dice_amount = dice_set.size();
    vector <vector <vector <int> > > consequences = get_sorted_consequences(dice_set);
    for (int i = 0; i < consequences.size(); i++)
    {
        double total_probability = 0;
        for (int j = 0; j < consequences[i].size(); j++)
        {
            double probability = 1;
            for (int k = 0; k < consequences[i][j].size(); k++)
            {
                probability *= dice_set[k].probability(consequences[i][j][k]);
            }
            total_probability += probability;
        }
        cout << "SUM: " << i + dice_amount << "\nPROBABILITY: " << total_probability << "\n\n";
    }
    return;
}