/**
 *  @brief  Creates an empty list.
 */
template <typename T>
List<T>::List() 
{
    start = nullptr;
}

/**
 *  @brief  Creates a list with a specific first element.
 */
template <typename T>
List<T>::List(T data) 
{
    start = new Node<T>(data);
}

template <typename T>
List<T>::~List()
{
    Node<T>* old;
    while (start)
    {
        old = start;
        start = start -> next;
        delete old;
    }
}
