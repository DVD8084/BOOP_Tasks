/**
 *  @brief  Creates an empty queue.
 */
 template <typename T>
QueueArray<T>::QueueArray()
{
}

/**
 *  @brief  Creates a queue with a specific first element.
 */
template <typename T>
QueueArray<T>::QueueArray(T data)
{
    queue[0] = data;
    queue_size = 1;
}

/**
 *  @brief  Prints the contents of a queue.
 */
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

/**
 *  @brief  Pushes an element to the queue.
 */
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

/**
 *  @brief  Peeks at the queue.
 */
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

/**
 *  @brief  Pops an element from the queue.
 */
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

/**
 *  @brief  Fills the queue with a fixed amount of random elements.
 *  @param  size  The amount of elements.
 */
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
