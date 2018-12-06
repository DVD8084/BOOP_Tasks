#include "test.h"

using std::vector;
using std::cout;

void dice_test()
{
    vector <Dice> dice_set;
    for (int i = 0; i < 2; i++)
    {
        dice_set.push_back(Dice(6));
    }
    vector <double> probabilities;
    for (int i = 0; i < 2; i++)
    {
        probabilities.push_back(i + 1);
    }
    vector <Dice> coin_set;
    for (int i = 0; i < 3; i++)
    {
        coin_set.push_back(Dice(2, probabilities));
    }
    cout << "[SET 1: 2 REGULAR DICE]\n";
    print_probabilities(dice_set);
    cout << "\n[SET 2: 3 UNFAIR COINS]\n[ p(0) = 1/3, p(1) = 2/3]\n";
    print_probabilities(coin_set);
    
}