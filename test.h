#ifndef TEST_H
#define TEST_H

#include <vector>
#include <iostream>
#include <windows.h>
#include "arrays.h"
#include "dice.h"
#include "lists.h"
#include "std.h"

using std::vector;
using std::cout;

#ifndef RANDOM_STRUCTURE_SIZE
#define RANDOM_STRUCTURE_SIZE 5
#endif

enum STRUCTURE_TYPE {STACK, QUEUE, DEQUE};
enum IMPLEMENTATION {ARRAY, LIST, STDLIB};

template <typename U, typename V>
void stack_queue_test(U structure, V type);

template <typename U, typename V>
void deque_test(U structure, V type);


template <typename T>
void structure_test(T element_type, int structure_type, int implementation);

void dice_test();

#include "test.tpp"

#endif