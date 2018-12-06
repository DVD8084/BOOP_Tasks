template <typename T>
DequeArray<T>::DequeArray()
{
}

template <typename T>
DequeArray<T>::DequeArray(T data)
{
    deque[0] = data;
    deque_size = 1;
}

template <typename T>
void DequeArray<T>::print()
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

template <typename T>
void DequeArray<T>::print_rev()
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

template <typename T>
int DequeArray<T>::push_start(T new_data)
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

template <typename T>
int DequeArray<T>::push_end(T new_data)
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

template <typename T>
T DequeArray<T>::peek_start()
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

template <typename T>
T DequeArray<T>::peek_end()
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

template <typename T>
T DequeArray<T>::pop_start()
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

template <typename T>
T DequeArray<T>::pop_end()
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

template <typename T>
void DequeArray<T>::fill_random(int size)
{
    deque_size = 0;
    deque_size = 0;
    while(deque_size < size && size < MAX_ARRAY_SIZE)
    {
        set_random(deque[deque_size]);
        ++deque_size;
    }
}
