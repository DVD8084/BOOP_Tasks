#include <iostream>
#include <cstdlib>
#include "lists.cpp"

using std::cout;

/*
 * Specialization of linked-list-based data structures for the int type.
 * Adds fill() function, which can be used to fill a data structure with random integers.
 */

/* Stack based on linked lists. */
template <>
class StackL<int> : public List<int>
{
public:
    StackL(int data) : List<int>(data)
    {
    }
    void print()
    {
        Node<int>* current = this -> start;
        while (current)
        {
            cout << current -> data;
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
    int push(int new_data)
    {
        Node<int>* new_start = new Node<int>(new_data, this -> start);
        this -> start = new_start;
        return new_data;
    }
    int peek()
    {
        return this -> start -> data;
    }
    int pop()
    {
        int popped = this -> start -> data;
        Node<int>* old = this -> start;
        this -> start = this -> start -> next;
        delete old;
        return popped;
    }
    void fill(int size)
    {
        delete this -> start;
        this -> start = new Node<int>(rand());
        Node<int>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            Node<int>* new_node = new Node<int>(rand());
            current -> next = new_node;
            current = new_node;
        }
    }
};

/* Queue based on linked lists. */
template <>
class QueueL<int> : public List<int>
{
private:
    Node<int>* end;
public:
    QueueL(int data) : List<int>(data)
    {
        this -> end = this -> start;
    }
    void print()
    {
        Node<int>* current = this -> start;
        while (current)
        {
            cout << current -> data;
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
    int push(int new_data)
    {
        Node<int>* new_end = new Node<int>(new_data);
        this -> end -> next = new_end;
        this -> end = new_end;
        return new_data;
    }
    int peek()
    {
        return this -> start -> data;
    }
    int pop()
    {
        int popped = this -> start -> data;
        Node<int>* old = this -> start;
        this -> start = this -> start -> next;
        delete old;
        return popped;
    }
    void fill(int size)
    {
        delete this -> start;
        this -> start = new Node<int>(rand());
        Node<int>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            Node<int>* new_node = new Node<int>(rand());
            current -> next = new_node;
            current = new_node;
        }
        this -> end = current;
    }
};

/* Deque (double-ended queue) based on linked lists. */
template <>
class DequeL<int> : public DoubleList<int>
{
public:
    DequeL(int data) : DoubleList<int>(data)
    {
    }
    void print()
    {
        DoubleNode<int>* current = this -> start;
        while (current)
        {
            cout << current -> data;
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
        DoubleNode<int>* current = this -> end;
        while (current)
        {
            cout << current -> data;
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
    int push_start(int new_data)
    {
        DoubleNode<int>* new_start = new DoubleNode<int>(new_data, this -> start);
        this -> start -> prev = new_start;
        this -> start = new_start;
        return new_data;
    }
    int push_end(int new_data)
    {
        DoubleNode<int>* new_end = new DoubleNode<int>(new_data, nullptr, this -> end);
        this -> end -> next = new_end;
        this -> end = new_end;
        return new_data;
    }
    int peek_start()
    {
        return this -> start -> data;
    }
    int peek_end()
    {
        return this -> end -> data;
    }
    int pop_start()
    {
        int popped = this -> start -> data;
        DoubleNode<int>* old = this -> start;
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
    int pop_end()
    {
        int popped = this -> end -> data;
        DoubleNode<int>* old = this -> end;
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
    void fill(int size)
    {
        delete this -> start;
        this -> start = new DoubleNode<int>(rand());
        DoubleNode<int>* current = this -> start;
        for (int i = 0; i < size - 1; i++)
        {
            DoubleNode<int>* new_node = new DoubleNode<int>(rand(), nullptr, current);
            current -> next = new_node;
            current = new_node;
        }
        this -> end = current;
    }
};