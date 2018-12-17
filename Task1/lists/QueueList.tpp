/**
 *  @brief  Creates an empty queue.
 */
template <typename T>
QueueList<T>::QueueList() : List<T>()
{
    this -> end = this -> start;
}

/**
 *  @brief  Creates a queue with a specific first element.
 */
template <typename T>
QueueList<T>::QueueList(T data) : List<T>(data)
{
    this -> end = this -> start;
}

/**
 *  @brief  Prints the contents of a queue.
 */
template <typename T>
void QueueList<T>::print()
{
    Node<T>* current = this -> start;
    while (current)
    {
        print_data(current -> data);
        if (current -> next)
        {
            print_data(" <- ");
        }
        else
        {
            print_data("\n");
        }
        current = current -> next;
    }  
}

/**
 *  @brief  Pushes an element to the queue.
 */
template <typename T>
int QueueList<T>::push(T new_data)
{
    Node<T>* new_end = new Node<T>(new_data);
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
 *  @brief  Peeks at the queue.
 */
template <typename T>
T QueueList<T>::peek()
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
 *  @brief  Pops an element from the queue.
 */
template <typename T>
T QueueList<T>::pop()
{
    if (this -> start)
    {
        T popped = this -> start -> data;
        Node<T>* old = this -> start;
        this -> start = this -> start -> next;
        delete old;
        return popped;
    }
    else
    {
        return get_empty<T>();
    }
}

/**
 *  @brief  Fills the queue with a fixed amount of random elements.
 *  @param  size  The amount of elements.
 */
template <typename T>
void QueueList<T>::fill_random(int size)
{
    delete this -> start;
    this -> start = new Node<T>(get_random<T>());
    Node<T>* current = this -> start;
    for (int i = 0; i < size - 1; i++)
    {
        Node<T>* new_node = new Node<T>(get_random<T>());
        current -> next = new_node;
        current = new_node;
    }
    this -> end = current;
}
