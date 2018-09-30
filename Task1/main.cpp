/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: DVD
 *
 * Created on 23 сентября 2018 г., 7:58
 */

#include <cstdlib>
#include <iostream>
#include "lists_int.cpp"
#include "arrays_int.cpp"

using std::cout;

/*
 * 
 */


int main(int argc, char** argv)
{
    
    /* StackL and QueueL testing. Change the type of test_obj to needed type.*/
    /*
    cout << "Creating...\n";
    StackL<int> test_obj(rand());
    test_obj.print();
    for (int i = 0; i < 4; i++) {
        cout << "Adding next element...\n";
        test_obj.push(rand());
        cout << "Current structure: ";
        test_obj.print();
    }
    cout << "Peeked at element ";
    cout << test_obj.peek() << '\n';
    for (int i = 0; i < 5; i++) {
        cout << "Current structure: ";
        test_obj.print();
        cout << "Popped element ";
        cout << test_obj.pop() << '\n';
    }
    cout << "Filling with random integers...\n";
    test_obj.fill(10);
    cout << "Current structure: ";
    test_obj.print();
    cout << "Filling with random integers...\n";
    test_obj.fill(10);
    cout << "Current structure: ";
    test_obj.print();
    */
    
    /* DequeL testing. Separate from stack & queue because uses different function names. */
    /*
    cout << "Creating...\n";
    DequeL<int> test_obj2(rand());
    test_obj2.print();
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (start)...\n";
        test_obj2.push_start(rand());
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
    }
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (end)...\n";
        test_obj2.push_end(rand());
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
    }
    cout << "Peeked at element " << test_obj2.peek_start() << " (start)\n";
    cout << "Peeked at element " << test_obj2.peek_end() << " (end)\n";
    for (int i = 0; i < 3; i++) {
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
        cout << "Popped element " << test_obj2.pop_start() << " (start)\n";
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
        cout << "Popped element " << test_obj2.pop_end() << " (end)\n";
    }
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    cout << "Filling with random integers...\n";
    test_obj2.fill(10);
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    cout << "Filling with random integers...\n";
    test_obj2.fill(10);
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    */
    
    
    return 0;
}

