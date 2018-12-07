#include "empty.h"

using std::vector;

/**
 *  These functions are used to set the supported types to respective empty values.
 *  The values are:
 *  (int) 0.
 *  (float) 0.
 *  (double) 0.
 *  (char) NULL character.
 *  (string) Empty string.
 *  (vector) Default vector.
 *  (Dice) Fair coin.
 */

void set_empty(int& data)
{
    data = 0;
}

void set_empty(float& data)
{
    data = 0;
}
void set_empty(double& data)
{
    data = 0;
}

void set_empty(char& data)
{
    data = 0;
}

void set_empty(std::string& data)
{
    data = "";
}

void set_empty(Dice& data)
{
    data = Dice(2);
}

