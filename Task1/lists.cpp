/*
 * Basic stack, queue and deque (double-ended queue) classes.
 * This implementation uses linked lists.
 */

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node()
    {
        set_empty(this -> data);
        this -> next = nullptr;
    }
    Node(T data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
    Node(T data, Node* next)
    {
        this -> data = data;
        this -> next = next;
    }
};

template <typename T>
class DoubleNode
{
public:
    T data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode()
    {
        set_empty(this -> data);
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    DoubleNode(T data)
    {
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    DoubleNode(T data, DoubleNode* next)
    {
        this -> data = data;
        this -> next = next;
        this -> prev = nullptr;
    }
    DoubleNode(T data, DoubleNode *next, DoubleNode *prev)
    {
        this -> data = data;
        this -> next = next;
        this -> prev = prev;
    }
};


/* Basic singly linked list. Used for StackL and QueueL. */
template <typename T>
class List
{
protected:
    Node<T>* start;
public:
    List() 
    {
        start = nullptr;
    }
    List(T data) 
    {
        start = new Node<T>(data);
    }
    virtual ~List()
    {
        Node<T>* old;
        while (start)
        {
            old = start;
            start = start -> next;
            delete old;
        }
    }
};

/* Basic doubly linked list. Used for DequeL. */
template <typename T>
class DoubleList
{
protected:
    DoubleNode<T>* start;
    DoubleNode<T>* end;
public:
    DoubleList() 
    {
        start = nullptr;
        end = start;
    }
    DoubleList(T data) 
    {
        start = new DoubleNode<T>(data);
        end = start;
    }
    virtual ~DoubleList()
    {
        DoubleNode<T>* old;
        while (start)
        {
            old = start;
            start = start -> next;
            delete old;
        }
    }
};

/* Stack based on linked lists. */
template <typename T>
class StackL : public List<T>
{
public:
    StackL() : List<T>()
    {
    }
    StackL(T data) : List<T>(data)
    {
    }
    void print()
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
    int push(T new_data)
    {
        Node<T>* new_start = new Node<T>(new_data, this -> start);
        this -> start = new_start;
        return 1;
    }
    T peek()
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
    T pop()
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
    void fill_random(int size)
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
};

/* Queue based on linked lists. */
template <typename T>
class QueueL : public List<T>
{
private:
    Node<T>* end;
public:
    QueueL() : List<T>()
    {
        this -> end = this -> start;
    }
    QueueL(T data) : List<T>(data)
    {
        this -> end = this -> start;
    }
    void print()
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
    int push(T new_data)
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
    T peek()
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
    T pop()
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
    void fill_random(int size)
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
};

/* Deque (double-ended queue) based on linked lists. */
template <typename T>
class DequeL : public DoubleList<T>
{
public:
    DequeL() : DoubleList<T>()
    {
    }
    DequeL(T data) : DoubleList<T>(data)
    {
    }
    void print()
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
    void print_rev()
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
    int push_start(T new_data)
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
    int push_end(T new_data)
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
    T peek_start()
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
    T peek_end()
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
    T pop_start()
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
    T pop_end()
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
    void fill_random(int size)
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
};