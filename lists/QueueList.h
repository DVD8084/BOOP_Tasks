#ifndef QUEUELIST_H
#define QUEUELIST_H

#include "List.h"

/**
 *  @brief  Queue based on linked lists.
 */
template <typename T>
class QueueList : public List<T>
{
private:
    Node<T>* end;
public:
    QueueList();
    QueueList(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "QueueList.tpp"

#endif