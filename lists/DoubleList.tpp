/**
 *  @brief  Creates an empty list.
 */
template <typename T>
DoubleList<T>::DoubleList() 
{
    start = nullptr;
    end = start;
}

/**
 *  @brief  Creates a list with a specific first element.
 */
template <typename T>
DoubleList<T>::DoubleList(T data) 
{
    start = new DoubleNode<T>(data);
    end = start;
}

template <typename T>
DoubleList<T>::~DoubleList()
{
    DoubleNode<T>* old;
    while (start)
    {
        old = start;
        start = start -> next;
        delete old;
    }
}
