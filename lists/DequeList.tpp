template <typename T>
DequeList<T>::DequeList() : DoubleList<T>()
{
}

template <typename T>
DequeList<T>::DequeList(T data) : DoubleList<T>(data)
{
}

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
