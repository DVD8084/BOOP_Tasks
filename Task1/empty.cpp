#include <vector>
#include <string>

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

template <typename T>
void set_empty(std::vector<T>& data)
{
    std::vector<T> vect;
    data = vect;
}