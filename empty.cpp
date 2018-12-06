#include "empty.h"

using std::vector;

/* These functions are used to generate empty elements of given type. */

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

