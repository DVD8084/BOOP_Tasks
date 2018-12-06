#ifndef STACKSTD_H
#define STACKSTD_H

#include <stack>

using std::stack;

/* Stack based on std::stack. */
template <typename T>
class StackStd {
private:
    stack<T> std_stack;
public:
    StackStd();
    StackStd(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "StackStd.tpp"

#endif