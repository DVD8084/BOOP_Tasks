template <typename T>
QueueArray<T>::QueueArray()
{
}

template <typename T>
QueueArray<T>::QueueArray(T data)
{
    queue[0] = data;
    queue_size = 1;
}

template <typename T>
void QueueArray<T>::print()
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

template <typename T>
int QueueArray<T>::push(T new_data)
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

template <typename T>
T QueueArray<T>::peek()
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

template <typename T>
T QueueArray<T>::pop()
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

template <typename T>
void QueueArray<T>::fill_random(int size)
{
    queue_start = 0;
    queue_size = 0;
    while(queue_size < size && size < MAX_ARRAY_SIZE)
    {
        set_random(queue[queue_size]);
        ++queue_size;
    }
}
