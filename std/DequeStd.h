#ifndef DEQUESTD_H
#define DEQUESTD_H

#include <deque>

using std::deque;

/**
 *  @brief  Deque (double-ended queue) based on std::deque.
 */
template <typename T>
class DequeStd {
private:
    deque<T> std_deque;
public:
    DequeStd();
    DequeStd(T data);
    void print();
    void print_rev();
    int push_start(T new_data);
    int push_end(T new_data);
    T peek_start();
    T peek_end();
    T pop_start();
    T pop_end();
    void fill_random(int size);
};

#include "DequeStd.tpp"

#endif