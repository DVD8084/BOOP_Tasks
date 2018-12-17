#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>
#include "dice.h"

using std::cout;

/* These functions are used to print elements of given type. */

void print_data(int data);

void print_data(float data);

void print_data(double data);

void print_data(char data);

void print_data(std::string data);

template <typename T>
void print_data(std::vector<T> data);

void print_data(Dice data);

#include "print.tpp"

#endif