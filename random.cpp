#include "random.h"

using std::vector;

/**
 *  These functions are used to set the supported types to respective random values.
 *  The values are:
 *  (int) Integer from 0 to RAND_MAX.
 *  (float) Float from 0 to 1.
 *  (double) Double from 0 to 1.
 *  (char) Non-control ASCII character.
 *  (string) RANDOM_STRING_SIZE non-control ASCII characters.
 *  (vector) RANDOM_VECTOR_SIZE vector elements.
 *  (Dice) Uneven die with 2, 4, 6, 8, 10, 12 or 20 sides.
 */
 
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
