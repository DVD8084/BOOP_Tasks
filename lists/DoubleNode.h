#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <typename T>
class DoubleNode
{
public:
    T data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode();
    DoubleNode(T data);
    DoubleNode(T data, DoubleNode* next);
    DoubleNode(T data, DoubleNode *next, DoubleNode *prev);
};

#include "DoubleNode.tpp"

#endif