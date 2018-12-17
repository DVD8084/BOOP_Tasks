/**
 *  @brief  Creates an empty deque.
 */
template <typename T>
DequeList<T>::DequeList() : DoubleList<T>()
{
}

/**
 *  @brief  Creates a deque with a specific first element.
 */
template <typename T>
DequeList<T>::DequeList(T data) : DoubleList<T>(data)
{
}

/**
 *  @brief  Prints the contents of a deque.
 */
template <typename T>
void DequeList<T>::print()
{
    DoubleNode<T>* current = this -> start;
    while (current)
    {
        print_data(current -> data);
        if (current -> next)
        {
            print_data(" <-> ");
        }
        else
        {
            print_data("\n");
        }
        current = current -> next;
    }  
}

/**
 *  @brief  Prints the contents of a deque in reverse order.
 */
template <typename T>
void DequeList<T>::print_rev()
{
    DoubleNode<T>* current = this -> end;
    while (current)
    {
        print_data(current -> data);
        if (current -> prev)
        {
            print_data(" <-> ");
        }
        else
        {
            print_data("\n");
        }
        current = current -> prev;
    }  
}

/**
 *  @brief  Pushes an element to the start of the deque.
 */
template <typename T>
int DequeList<T>::push_start(T new_data)
{
    DoubleNode<T>* new_start = new DoubleNode<T>(new_data, this -> start);
    if (this -> start)
    {
        this -> start -> prev = new_start;
    }
    this -> start = new_start;
    if (!this -> end)
    {
        this -> end = this -> start;
    }
    return 1;
}

/**
 *  @brief  Pushes an element to the end of the deque.
 */
template <typename T>
int DequeList<T>::push_end(T new_data)
{
    DoubleNode<T>* new_end = new DoubleNode<T>(new_data, nullptr, this -> end);
    if (this -> end)
    {
        this -> end -> next = new_end;
    }
    this -> end = new_end;
    if (!this -> start)
    {
        this -> start = this -> end;
    }
    return 1;
}

/**
 *  @brief  Peeks at the element at the start of the deque.
 */
template <typename T>
T DequeList<T>::peek_start()
{
    if (this -> start)
    {
        return this -> start -> data;
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
T DequeList<T>::peek_end()
{
    if (this -> end)
    {
        return this -> end -> data;
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
T DequeList<T>::pop_start()
{
    if (this -> start)
    {
        T popped = this -> start -> data;
        DoubleNode<T>* old = this -> start;
        this -> start = this -> start -> next;
        if (this -> start)
        {
        this -> start -> prev = nullptr;
        }
        else
        {
            this -> end = nullptr;
        }
        delete old;
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
T DequeList<T>::pop_end()
{
    if (this -> end)
    {
        T popped = this -> end -> data;
        DoubleNode<T>* old = this -> end;
        this -> end = this -> end -> prev;
        if (this -> end)
        {
            this -> end -> next = nullptr;
        }
        else
        {
            this -> start = nullptr;
        }
        delete old;
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
void DequeList<T>::fill_random(int size)
{
    delete this -> start;
    this -> start = new DoubleNode<T>(get_random<T>());
    DoubleNode<T>* current = this -> start;
    for (int i = 0; i < size - 1; i++)
    {
        DoubleNode<T>* new_node = new DoubleNode<T>(get_random<T>(), nullptr, current);
        current -> next = new_node;
        current = new_node;
    }
    this -> end = current;
}
