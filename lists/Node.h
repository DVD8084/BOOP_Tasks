#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node();
    Node(T data);
    Node(T data, Node* next);
};

#include "Node.tpp"

#endif