#ifndef STACKARRAY_H
#define STACKARRAY_H

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

/**
 *  @brief  Stack based on arrays.
 */
template <typename T>
class StackArray
{
private:
    T stack[MAX_ARRAY_SIZE];
    int stack_size = 0;
public:
    StackArray();
    StackArray(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "StackArray.tpp"

#endif