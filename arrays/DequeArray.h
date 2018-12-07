#ifndef DEQUEARRAY_H
#define DEQUEARRAY_H

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

/**
 *  @brief  Deque (double-ended queue) based on arrays.
 */
template <typename T>
class DequeArray
{
private:
    T deque[MAX_ARRAY_SIZE];
    int deque_start = 0, deque_size = 0;
public:
    DequeArray();
    DequeArray(T data);
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

#include "DequeArray.tpp"

#endif