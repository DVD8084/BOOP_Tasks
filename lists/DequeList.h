#ifndef DEQUELIST_H
#define DEQUELIST_H

#include "DoubleList.h"

/* Deque (double-ended queue) based on linked lists. */
template <typename T>
class DequeList : public DoubleList<T>
{
public:
    DequeList();
    DequeList(T data);
    void print();
    void print_rev();
    int push_start(T new_data);
    int push_end(T new_data);
    T peek_start();
    T peek_end();
    T pop_start();
    T pop_end();
    void fill_random(int size);
};

#include "DequeList.tpp"

#endif