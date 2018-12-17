template <typename T>
QueueStd<T>::QueueStd()
{
}

template <typename T>
QueueStd<T>::QueueStd(T data)
{
    std_queue.push(data);
}

template <typename T>
void QueueStd<T>::print()
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

template <typename T>
int QueueStd<T>::push(T new_data)
{
    std_queue.push(new_data);
    return 1;
}

template <typename T>
T QueueStd<T>::peek()
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

template <typename T>
T QueueStd<T>::pop()
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

template <typename T>
void QueueStd<T>::fill_random(int size)
{
    queue<T> new_queue;
    std_queue = new_queue;
    for(int i = 0; i < size; i++)
    {
        std_queue.push(get_random<T>());
    }
}
