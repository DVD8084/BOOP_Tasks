#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

/*
 * Basic stack, queue and deque (double-ended queue) classes.
 * This implementation uses arrays.
 */

/* Stack based on arrays. */
template <typename T>
class StackA
{
private:
    T stack[MAX_ARRAY_SIZE];
    int stack_size = 0;
public:
    StackA()
    {
    }
    StackA(T data)
    {
        stack[0] = data;
        stack_size = 1;
    }
    void print()
    {
        for (int i = 0; i < stack_size; i++)
        {
            print_data(stack[i]);
            if (i < stack_size - 1)
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
        if (stack_size < MAX_ARRAY_SIZE)
        {
            stack[stack_size++] = new_data;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    T peek()
    {
        if (stack_size)
        {
            return stack[stack_size - 1];
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop()
    {
        if (stack_size)
        {
            return stack[--stack_size];
        }
        else
        {
            return get_empty<T>();
        }
    }
    void fill_random(int size)
    {
        stack_size = 0;
        while(stack_size < size && size < MAX_ARRAY_SIZE)
        {
            set_random(stack[stack_size]);
            ++stack_size;
        }
    }
};

/* Queue based on arrays. */
template <typename T>
class QueueA
{
private:
    T queue[MAX_ARRAY_SIZE];
    int queue_start = 0, queue_size = 0;
public:
    QueueA()
    {
    }
    QueueA(T data)
    {
        queue[0] = data;
        queue_size = 1;
    }
    void print()
    {
        for (int i = 0; i < queue_size; i++)
        {
            print_data(queue[(queue_start + i) % MAX_ARRAY_SIZE]);
            if (i < queue_size - 1)
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
        if (queue_size < MAX_ARRAY_SIZE)
        {
            queue[(queue_start + queue_size) % MAX_ARRAY_SIZE] = new_data;
            ++queue_size;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    T peek()
    {
        if (queue_size)
        {
            return queue[queue_start];
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop()
    {
        T popped = queue[queue_start];
        if (queue_size)
        {
            --queue_size;
            ++queue_start;
            queue_start = (queue_start == MAX_ARRAY_SIZE) ? 0 : queue_start;
        }
        else
        {
            set_empty(popped);
        }
        return popped;
    }
    void fill_random(int size)
    {
        queue_start = 0;
        queue_size = 0;
        while(queue_size < size && size < MAX_ARRAY_SIZE)
        {
            set_random(queue[queue_size]);
            ++queue_size;
        }
    }
};

/* Deque (double-ended queue) based on arrays. */
template <typename T>
class DequeA
{
private:
    T deque[MAX_ARRAY_SIZE];
    int deque_start = 0, deque_size = 0;
public:
    DequeA()
    {
    }
    DequeA(T data)
    {
        deque[0] = data;
        deque_size = 1;
    }
    void print()
    {
        for (int i = 0; i < deque_size; i++)
        {
            print_data(deque[(deque_start + i) % MAX_ARRAY_SIZE]);
            if (i < deque_size - 1)
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
        for (int i = deque_size - 1; i >= 0; i--)
        {
            print_data(deque[(deque_start + i) % MAX_ARRAY_SIZE]);
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
        if (deque_size < MAX_ARRAY_SIZE)
        {
            ++deque_size;
            --deque_start;
            deque_start = (deque_start < 0) ? MAX_ARRAY_SIZE + deque_start : deque_start;
            deque[deque_start] = new_data;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int push_end(T new_data)
    {
        if (deque_size < MAX_ARRAY_SIZE)
        {
            deque[(deque_start + deque_size) % MAX_ARRAY_SIZE] = new_data;
            ++deque_size;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    T peek_start()
    {
        if (deque_size)
        {
            return deque[deque_start];
        }
        else
        {
            return get_empty<T>();
        }
    }
    T peek_end()
    {
        if (deque_size)
        {
            return deque[(deque_start + deque_size - 1) % MAX_ARRAY_SIZE];
        }
        else
        {
            return get_empty<T>();
        }
    }
    T pop_start()
    {
        T popped = deque[deque_start];
        if (deque_size)
        {
            --deque_size;
            ++deque_start;
            deque_start = (deque_start == MAX_ARRAY_SIZE) ? 0 : deque_start;
        }
        else
        {
            set_empty(popped);
        }
        return popped;
    }
    T pop_end()
    {
        if (deque_size)
        {
            --deque_size;
            return deque[(deque_start + deque_size) % MAX_ARRAY_SIZE];
        }
        else
        {
            return get_empty<T>();
        }
    }
    void fill_random(int size)
    {
        deque_size = 0;
        deque_size = 0;
        while(deque_size < size && size < MAX_ARRAY_SIZE)
        {
            set_random(deque[deque_size]);
            ++deque_size;
        }
    }
};