template <typename T>
QueueList<T>::QueueList() : List<T>()
{
    this -> end = this -> start;
}

template <typename T>
QueueList<T>::QueueList(T data) : List<T>(data)
{
    this -> end = this -> start;
}

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
