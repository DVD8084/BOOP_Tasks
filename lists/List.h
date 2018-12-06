#ifndef LIST_H
#define LIST_H

#include "Node.h"

/* Basic singly linked list. Used for StackList and QueueList. */
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