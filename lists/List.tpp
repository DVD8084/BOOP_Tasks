template <typename T>
List<T>::List() 
{
    start = nullptr;
}

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
