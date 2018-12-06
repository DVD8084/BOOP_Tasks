#include "random.h"

using std::vector;

/* These functions are used to generate random elements of given type in order to fill a data structure with random elements. */

void set_random(int& data)
{
    data = rand();
}

void set_random(float& data)
{
    data = (float)rand() / RAND_MAX;
}
void set_random(double& data)
{
    data = (double)rand() / RAND_MAX;
}

void set_random(char& data)
{
    data = rand() % 96 + 32;
}

void set_random(std::string& data)
{
    std::string str = "";
    for (int i = 0; i < RANDOM_STRING_SIZE; i++)
    {
        char chr;
        set_random(chr);
        str += chr;
    }
    data = str;
}

void set_random(Dice& data)
{
    int side_amount = (rand() % 7 + 1) * 2;
    if (side_amount == 14)
    {
        side_amount = 20;
    }
    vector <double> probabilities (side_amount, 0);
    for (int i = 0; i < side_amount; i++)
    {
        set_random(probabilities[i]);
    }
    data = Dice(side_amount, probabilities);
}
