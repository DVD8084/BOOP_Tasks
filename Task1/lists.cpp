#include <iostream>
#include <cstdlib>

using std::cout;

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
        this->data = 0;
        this->next = nullptr;
    }
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(T data, Node* next)
    {
        this->data = data;
        this->next = next;
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
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    DoubleNode(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    DoubleNode(T data, DoubleNode* next)
    {
        this->data = data;
        this->next = next;
        this->prev = nullptr;
    }
    DoubleNode(T data, DoubleNode *next, DoubleNode *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};


/* Basic singly linked list. Used for StackL and QueueL. */
template <typename T>
class List
{
protected:
    Node<T>* start;
public:
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
                cout << " -> ";
            }
            else
            {
                cout << '\n';
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
        return this -> start -> data;
    }
    T pop()
    {
        T popped = this -> start -> data;
        Node<T>* old = this -> start;
        this -> start = this -> start -> next;
        delete old;
        return popped;
    }
    void fill_random(int size)
    {
        delete this -> start;
        T type;
        this -> start = new Node<T>(get_random(type));
        Node<T>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            Node<T>* new_node = new Node<T>(get_random(type));
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
                cout << " <- ";
            }
            else
            {
                cout << '\n';
            }
            current = current -> next;
        }  
    }
    int push(T new_data)
    {
        Node<T>* new_end = new Node<T>(new_data);
        this -> end -> next = new_end;
        this -> end = new_end;
        return 1;
    }
    T peek()
    {
        return this -> start -> data;
    }
    T pop()
    {
        T popped = this -> start -> data;
        Node<T>* old = this -> start;
        this -> start = this -> start -> next;
        delete old;
        return popped;
    }
    void fill_random(int size)
    {
        delete this -> start;
        T type;
        this -> start = new Node<T>(get_random(type));
        Node<T>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            Node<T>* new_node = new Node<T>(get_random(type));
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
                cout << " <-> ";
            }
            else
            {
                cout << '\n';
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
                cout << " <-> ";
            }
            else
            {
                cout << '\n';
            }
            current = current -> prev;
        }  
    }
    int push_start(T new_data)
    {
        DoubleNode<T>* new_start = new DoubleNode<T>(new_data, this -> start);
        this -> start -> prev = new_start;
        this -> start = new_start;
        return 1;
    }
    int push_end(T new_data)
    {
        DoubleNode<T>* new_end = new DoubleNode<T>(new_data, nullptr, this -> end);
        this -> end -> next = new_end;
        this -> end = new_end;
        return 1;
    }
    T peek_start()
    {
        return this -> start -> data;
    }
    T peek_end()
    {
        return this -> end -> data;
    }
    T pop_start()
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
    T pop_end()
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
    void fill_random(int size)
    {
        delete this -> start;
        T type;
        this -> start = new DoubleNode<T>(get_random(type));
        DoubleNode<T>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            DoubleNode<T>* new_node = new DoubleNode<T>(get_random(type), nullptr, current);
            current -> next = new_node;
            current = new_node;
        }
        this -> end = current;
    }
};