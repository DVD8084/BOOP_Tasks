/**
 *  @brief  Creates an empty deque.
 */
template <typename T>
DequeStd<T>::DequeStd()
{
}

/**
 *  @brief  Creates a deque with a specific first element.
 */
template <typename T>
DequeStd<T>::DequeStd(T data)
{
    std_deque.push_front(data);
}

/**
 *  @brief  Prints the contents of a deque.
 */
template <typename T>
void DequeStd<T>::print()
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

/**
 *  @brief  Prints the contents of a deque in reverse order.
 */
template <typename T>
void DequeStd<T>::print_rev()
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

/**
 *  @brief  Pushes an element to the start of the deque.
 */
template <typename T>
int DequeStd<T>::push_start(T new_data)
{
    std_deque.push_front(new_data);
    return 1;
}

/**
 *  @brief  Pushes an element to the end of the deque.
 */
template <typename T>
int DequeStd<T>::push_end(T new_data)
{
    std_deque.push_back(new_data);
    return 1;
}

/**
 *  @brief  Peeks at the element at the start of the deque.
 */
template <typename T>
T DequeStd<T>::peek_start()
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

/**
 *  @brief  Peeks at the element at the end of the deque.
 */
template <typename T>
T DequeStd<T>::peek_end()
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

/**
 *  @brief  Pops an element at the start of the deque.
 */
template <typename T>
T DequeStd<T>::pop_start()
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

/**
 *  @brief  Pops an element at the end of the deque.
 */
template <typename T>
T DequeStd<T>::pop_end()
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

/**
 *  @brief  Fills the deque with a fixed amount of random elements.
 *  @param  size  The amount of elements.
 */
template <typename T>
void DequeStd<T>::fill_random(int size)
{
    deque<T> new_deque;
    std_deque = new_deque;
    for(int i = 0; i < size; i++)
    {
        std_deque.push_front(get_random<T>());
    }
}
