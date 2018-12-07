#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

/**
 *  @brief  Queue based on arrays.
 */
template <typename T>
class QueueArray
{
private:
    T queue[MAX_ARRAY_SIZE];
    int queue_start = 0, queue_size = 0;
public:
    QueueArray();
    QueueArray(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "QueueArray.tpp"

#endif