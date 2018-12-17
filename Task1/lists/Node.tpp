/**
 *  @brief  Creates an empty node.
 */
 template <typename T>
Node<T>::Node()
{
    set_empty(this -> data);
    this -> next = nullptr;
}

/**
 *  @brief  Creates a node with specific data.
 */
template <typename T>
Node<T>::Node(T data)
{
    this -> data = data;
    this -> next = nullptr;
}

/**
 *  @brief  Creates a node with specific data and a pointer to the next node.
 */
template <typename T>
Node<T>::Node(T data, Node* next)
{
    this -> data = data;
    this -> next = next;
}
