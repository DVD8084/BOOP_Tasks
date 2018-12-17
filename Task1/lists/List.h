#ifndef LIST_H
#define LIST_H

#include "Node.h"

/**
 *  @brief  Basic singly linked list. Used for StackList and QueueList classes.
 */
template <typename T>
class List
{
protected:
    Node<T>* start;
public:
    List();
    List(T data);
    virtual ~List();
};

#include "List.tpp"

#endif