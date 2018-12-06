template <typename T>
DoubleList<T>::DoubleList() 
{
    start = nullptr;
    end = start;
}

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
