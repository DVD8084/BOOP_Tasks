#include <stack>
#include <queue>
#include <deque>

using std::stack;
using std::queue;
using std::deque;

/*
 * Basic stack, queue and deque (double-ended queue) classes.
 * This implementation uses std::stack, std::queue and std::deque classes.
 */

/* Stack based on std::stack. */
template <typename T>
class StackStd {
private:
    stack<T> std_stack;
public:
    StackStd()
    {
    }
    StackStd(T data)
    {
        std_stack.push(data);
    }
    void print()
    {
        stack<T> stack_copy = std_stack;
        while (stack_copy.size())
        {
            print_data(stack_copy.top());
            stack_copy.pop();
            if (stack_copy.size())
            {
                print_data(" <- ");
            }
            else
            {
                print_data("\n");
            }
        }
    }
    int push(T new_data)
    {
        std_stack.push(new_data);
        return 1;
    }
    T peek()
    {
        if (std_stack.size())
        {
            return std_stack.top();
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop()
    {
        if (std_stack.size())
        {
            T popped = std_stack.top();
            std_stack.pop();
            return popped;
        }
        else
        {
            return get_empty<T>();
        }
    }
    void fill_random(int size)
    {
        stack<T> new_stack;
        std_stack = new_stack;
        for(int i = 0; i < size; i++)
        {
            std_stack.push(get_random<T>());
        }
    }
};

/* Queue based on std::queue. */
template <typename T>
class QueueStd {
private:
    queue<T> std_queue;
public:
    QueueStd()
    {
    }
    QueueStd(T data)
    {
        std_queue.push(data);
    }
    void print()
    {
        queue<T> queue_copy = std_queue;
        while (queue_copy.size())
        {
            print_data(queue_copy.front());
            queue_copy.pop();
            if (queue_copy.size())
            {
                print_data(" <- ");
            }
            else
            {
                print_data("\n");
            }
        }
    }
    int push(T new_data)
    {
        std_queue.push(new_data);
        return 1;
    }
    T peek()
    {
        if (std_queue.size())
        {
            return std_queue.front();
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop()
    {
        if (std_queue.size())
        {
            T popped = std_queue.front();
            std_queue.pop();
            return popped;
        }
        else
        {
            return get_empty<T>();
        }
    }
    void fill_random(int size)
    {
        queue<T> new_queue;
        std_queue = new_queue;
        for(int i = 0; i < size; i++)
        {
            std_queue.push(get_random<T>());
        }
    }
};

/* Deque (double-ended queue) based on std::deque. */
template <typename T>
class DequeStd {
private:
    deque<T> std_deque;
public:
    DequeStd()
    {
    }
    DeqeS(T data)
    {
        std_deque.push_front(data);
    }
    void print()
    {
        for (int i = 0; i < std_deque.size(); i++)
        {
            print_data(std_deque[i]);
            if (i < std_deque.size() - 1)
            {
                print_data(" <-> ");
            }
            else
            {
                print_data("\n");
            }
        }
    }
    void print_rev()
    {
        for (int i = std_deque.size() - 1; i >= 0; i--)
        {
            print_data(std_deque[i]);
            if (i > 0)
            {
                print_data(" <-> ");
            }
            else
            {
                print_data("\n");
            }
        }
    }
    int push_start(T new_data)
    {
        std_deque.push_front(new_data);
        return 1;
    }
    int push_end(T new_data)
    {
        std_deque.push_back(new_data);
        return 1;
    }
    T peek_start()
    {
        if (std_deque.size())
        {
            return std_deque.front();
        }
        else
        {
            return get_empty<T>();
        }
    }
    T peek_end()
    {
        if (std_deque.size())
        {
            return std_deque.back();
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop_start()
    {
        if (std_deque.size())
        {
            T popped = std_deque.front();
            std_deque.pop_front();
            return popped;
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop_end()
    {
        if (std_deque.size())
        {
            T popped = std_deque.back();
            std_deque.pop_back();
            return popped;
        }
        else
        {
            return get_empty<T>();
        }
    }
    void fill_random(int size)
    {
        deque<T> new_deque;
        std_deque = new_deque;
        for(int i = 0; i < size; i++)
        {
            std_deque.push_front(get_random<T>());
        }
    }
};