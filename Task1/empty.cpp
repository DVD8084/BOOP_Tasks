#include <vector>
#include <string>

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

template <typename T>
void set_empty(vector<T>& data)
{
    vector<T> vect;
    data = vect;
}

void set_empty(Dice& data)
{
    data = Dice(2);
}

template <typename T>
T get_empty()
{
    T data;
    set_empty(data);
    return data;
}