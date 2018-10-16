#include <vector>
#include <iostream>
#include <windows.h>

using std::cout;

#ifndef RANDOM_STRUCTURE_SIZE
#define RANDOM_STRUCTURE_SIZE 5
#endif

enum STRUCTURE_TYPE {STACK, QUEUE, DEQUE};
enum IMPLEMENTATION {ARRAY, LIST, STDLIB};

template <typename U, typename V>
void stack_queue_test(U structure, V type)
{
    cout << "[PUSHING TEST]\n";
    for (int i = 0; i < 5; i++) {
        cout << "Adding next element...\n";
        structure.push(get_random<V>());
        cout << "Current structure: ";
        structure.print();
    }
    cout << "[TEST END]\n\n";
    
    cout << "[PEEKING TEST]\n";
    cout << "Peeked at element ";
    print_data(structure.peek());
    cout << "\n[TEST END]\n\n";
    
    cout << "[POPPING TEST]\n";
    for (int i = 0; i < 5; i++) {
        cout << "Popped element ";
        print_data(structure.pop());
        cout << "\nCurrent structure: ";
        structure.print();
    }
    cout << "\n[TEST END]\n\n";
    
    cout << "[RANDOM FILLING TEST]\n";
    cout << "Filling with random elements...\n";
    structure.fill_random(RANDOM_STRUCTURE_SIZE);
    cout << "Current structure: ";
    structure.print();
    cout << "Filling with random elements...\n";
    structure.fill_random(RANDOM_STRUCTURE_SIZE);
    cout << "Current structure: ";
    structure.print();
    cout << "[TEST END]\n";
    
    return;
}

template <typename U, typename V>
void deque_test(U structure, V type)
{
    cout << "[PUSHING TEST]\n";
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (start)...\n";
        structure.push_start(get_random<V>());
        cout << "Current structure: ";
        structure.print();
    }
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (end)...\n";
        structure.push_end(get_random<V>());
        cout << "Current structure: ";
        structure.print();
    }
    cout << "[TEST END]\n\n";
    
    cout << "[OUTPUT TEST]\n";
    cout << "Current structure: ";
    structure.print();
    cout << "Current structure (reversed): ";
    structure.print_rev();
    cout << "[TEST END]\n\n";
    
    cout << "[PEEKING TEST]\n";
    cout << "Peeked at element ";
    print_data(structure.peek_start());
    cout << " (start)\n";
    cout << "Peeked at element ";
    print_data(structure.peek_end());
    cout << " (end)\n";
    cout << "[TEST END]\n\n";
    
    cout << "[POPPING TEST]\n";
    for (int i = 0; i < 3; i++) {
        cout << "Popped element ";
        print_data(structure.pop_start());
        cout << " (start)\n";
        cout << "Current structure: ";
        structure.print();
        cout << "Popped element ";
        print_data(structure.pop_end());
        cout << " (end)\n";
        cout << "Current structure: ";
        structure.print();
    }
    cout << "\n[TEST END]\n\n";
    
    cout << "[RANDOM FILLING TEST]\n";
    cout << "Filling with random elements...\n";
    structure.fill_random(RANDOM_STRUCTURE_SIZE);
    cout << "Current structure: ";
    structure.print();
    cout << "Filling with random elements...\n";
    structure.fill_random(RANDOM_STRUCTURE_SIZE);
    cout << "Current structure: ";
    structure.print();
    cout << "[TEST END]\n";
    
    return;
}


template <typename T>
void structure_test(T element_type, int structure_type, int implementation)
{
    if (structure_type / 3)
    {
        structure_type = 0;
    }
    if (implementation / 3)
    {
        implementation = 0;
    }
    switch (structure_type * 3 + implementation)
    {
        case 0:
        {
            StackA <T> stack;
            stack_queue_test(stack, element_type);
            break;
        }
        case 1:
        {
            StackL <T> stack;
            stack_queue_test(stack, element_type);
            break;
        }
        case 2:
        {
            StackS <T> stack;
            stack_queue_test(stack, element_type);
            break;
        }
        case 3:
        {
            QueueA <T> queue;
            stack_queue_test(queue, element_type);
            break;
        }
        case 4:
        {
            QueueL <T> queue;
            stack_queue_test(queue, element_type);
            break;
        }
        case 5:
        {
            QueueS <T> queue;
            stack_queue_test(queue, element_type);
            break;
        }
        case 6:
        {
            DequeA <T> deque;
            deque_test(deque, element_type);
            break;
        }
        case 7:
        {
            DequeL <T> deque;
            deque_test(deque, element_type);
            break;
        }
        case 8:
        {
            DequeS <T> deque;
            deque_test(deque, element_type);
            break;
        }
    }
    return;
}

void dice_test()
{
    vector <Dice> dice_set;
    for (int i = 0; i < 2; i++)
    {
        dice_set.push_back(Dice(6));
    }
    vector <double> probabilities;
    for (int i = 0; i < 2; i++)
    {
        probabilities.push_back(i + 1);
    }
    vector <Dice> coin_set;
    for (int i = 0; i < 3; i++)
    {
        coin_set.push_back(Dice(2, probabilities));
    }
    cout << "[SET 1: 2 REGULAR DICE]\n";
    print_probabilities(dice_set);
    cout << "\n[SET 2: 3 UNFAIR COINS]\n[ p(0) = 1/3, p(1) = 2/3]\n";
    print_probabilities(coin_set);
    
}