#ifndef EMPTY_H
#define EMPTY_H

#include <vector>
#include <string>
#include "dice.h"

using std::vector;

/* These functions are used to generate empty elements of given type. */

void set_empty(int& data);

void set_empty(float& data);

void set_empty(double& data);

void set_empty(char& data);

void set_empty(std::string& data);

template <typename T>
void set_empty(vector<T>& data);

void set_empty(Dice& data);

template <typename T>
T get_empty();

#include "empty.tpp"

#endif