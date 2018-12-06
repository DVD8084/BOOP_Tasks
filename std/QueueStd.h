#ifndef QUEUESTD_H
#define QUEUESTD_H

#include <queue>

using std::queue;

/* Queue based on std::queue. */
template <typename T>
class QueueStd {
private:
    queue<T> std_queue;
public:
    QueueStd();
    QueueStd(T data);
    void print();
    int push(T new_data);
    T peek();
    T pop();
    void fill_random(int size);
};

#include "QueueStd.tpp"

#endif