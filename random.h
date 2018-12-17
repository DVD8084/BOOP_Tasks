#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <vector>
#include <string>
#include "dice.h"

#ifndef RANDOM_STRING_SIZE
#define RANDOM_STRING_SIZE 10
#endif
#ifndef RANDOM_VECTOR_SIZE
#define RANDOM_VECTOR_SIZE 3
#endif

using std::vector;

/* These functions are used to generate random elements of given type in order to fill a data structure with random elements. */

void set_random(int& data);

void set_random(float& data);

void set_random(double& data);

void set_random(char& data);

void set_random(std::string& data);

template <typename T>
void set_random(vector<T>& data);

void set_random(Dice& data);

template <typename T>
T get_random();

#include "random.tpp"

#endif