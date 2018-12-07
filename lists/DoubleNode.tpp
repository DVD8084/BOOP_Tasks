/**
 *  @brief  Creates an empty node.
 */
template <typename T>
DoubleNode<T>::DoubleNode()
{
    set_empty(this -> data);
    this -> next = nullptr;
    this -> prev = nullptr;
}

/**
 *  @brief  Creates a node with specific data.
 */
template <typename T>
DoubleNode<T>::DoubleNode(T data)
{
    this -> data = data;
    this -> next = nullptr;
    this -> prev = nullptr;
}

/**
 *  @brief  Creates a node with specific data and a pointer to the next node.
 */
template <typename T>
DoubleNode<T>::DoubleNode(T data, DoubleNode* next)
{
    this -> data = data;
    this -> next = next;
    this -> prev = nullptr;
}

/**
 *  @brief  Creates a node with specific data and pointers to the next and previous nodes.
 */
template <typename T>
DoubleNode<T>::DoubleNode(T data, DoubleNode *next, DoubleNode *prev)
{
    this -> data = data;
    this -> next = next;
    this -> prev = prev;
}
