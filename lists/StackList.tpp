template <typename T>
StackList<T>::StackList() : List<T>()
{
}

template <typename T>
StackList<T>::StackList(T data) : List<T>(data)
{
}

template <typename T>
void StackList<T>::print()
{
    Node<T>* current = this -> start;
    while (current)
    {
        print_data(current -> data);
        if (current -> next)
        {
            print_data(" -> ");
        }
        else
        {
            print_data("\n");
        }
        current = current -> next;
    }  
}

template <typename T>
int StackList<T>::push(T new_data)
{
    Node<T>* new_start = new Node<T>(new_data, this -> start);
    this -> start = new_start;
    return 1;
}

template <typename T>
T StackList<T>::peek()
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
T StackList<T>::pop()
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
void StackList<T>::fill_random(int size)
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
}
