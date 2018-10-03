#include <cstdlib>
#include <vector>
#include <string>

#ifndef RANDOM_STRING_SIZE
#define RANDOM_STRING_SIZE 10
#endif
#ifndef RANDOM_VECTOR_SIZE
#define RANDOM_VECTOR_SIZE 3
#endif

/* These functions are used internally to generate random elements of given type in order to fill a data structure with random elements. */

int get_random(int type)
{
    return rand();
}

float get_random(float type)
{
    return (float)rand() / RAND_MAX;
}

double get_random(double type)
{
    return (double)rand() / RAND_MAX;
}

char get_random(char type)
{
    return rand() % 96 + 32;
}

std::string get_random(std::string type)
{
    std::string str = "";
    for (int i = 0; i < RANDOM_STRING_SIZE; i++)
    {
        char type;
        str += get_random(type);
    }
    return str;
}

template <typename T>
std::vector<T> get_random(std::vector<T> type)
{
    std::vector<T> vect;
    T subtype;
    for (int i = 0; i < RANDOM_VECTOR_SIZE; i++)
    {
        vect.push_back(get_random(subtype));
    }
    return vect;
}