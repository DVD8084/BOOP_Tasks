#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "DoubleNode.h"

/* Basic doubly linked list. Used for DequeList. */
template <typename T>
class DoubleList
{
protected:
    DoubleNode<T>* start;
    DoubleNode<T>* end;
public:
    DoubleList();
    DoubleList(T data);
    virtual ~DoubleList();
};

#include "DoubleList.tpp"

#endif