#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Dice
{
private:
    int sides = 2;
    vector <double> probabilities;
    void normalize();
public:
    Dice(); 
    Dice(int sides);
    Dice(int sides, vector<double> probabilities);
    int side_amount();
    double probability(int i);
};

vector <vector <int> > get_roll_consequences(vector <Dice> dice_set);

vector <vector <vector <int> > > get_sorted_consequences(vector <Dice> dice_set);

void print_probabilities(vector <Dice> dice_set);

#endif