template <typename T>
DoubleNode<T>::DoubleNode()
{
    set_empty(this -> data);
    this -> next = nullptr;
    this -> prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(T data)
{
    this -> data = data;
    this -> next = nullptr;
    this -> prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(T data, DoubleNode* next)
{
    this -> data = data;
    this -> next = next;
    this -> prev = nullptr;
}

template <typename T>
DoubleNode<T>::DoubleNode(T data, DoubleNode *next, DoubleNode *prev)
{
    this -> data = data;
    this -> next = next;
    this -> prev = prev;
}
