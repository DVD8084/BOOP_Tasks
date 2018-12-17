#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "DoubleNode.h"

/**
 *  @brief  Basic doubly linked list. Used for DequeList class.
 */
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