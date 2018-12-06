template <typename T>
Node<T>::Node()
{
    set_empty(this -> data);
    this -> next = nullptr;
}

template <typename T>
Node<T>::Node(T data)
{
    this -> data = data;
    this -> next = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node* next)
{
    this -> data = data;
    this -> next = next;
}
