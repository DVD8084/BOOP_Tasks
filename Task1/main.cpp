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
#include "random.cpp"
#include "print.cpp"
#include "lists.cpp"
#include "arrays.cpp"

using std::cout;

/*
 * 
 */


int main(int argc, char** argv)
{
    
    /* Stack? and Queue? testing. Change the type of test_obj to needed type.*/
    /*
    cout << "Creating...\n";
    char type;
    StackA<char> test_obj(get_random(type));
    test_obj.print();
    for (int i = 0; i < 4; i++) {
        cout << "Adding next element...\n";
        test_obj.push(get_random(type));
        cout << "Current structure: ";
        test_obj.print();
    }
    cout << "Peeked at element ";
    print_data(test_obj.peek());
    cout << '\n';
    for (int i = 0; i < 5; i++) {
        cout << "Current structure: ";
        test_obj.print();
        cout << "Popped element ";
        print_data(test_obj.pop());
        cout << '\n';
    }
    cout << "Filling with random elements...\n";
    test_obj.fill_random(10);
    cout << "Current structure: ";
    test_obj.print();
    cout << "Filling with random elements...\n";
    test_obj.fill_random(10);
    cout << "Current structure: ";
    test_obj.print();
    */
    
    /* Deque? testing. Separate from stack & queue because uses different function names. */
    /*
    cout << "Creating...\n";
    double type;
    DequeA<double> test_obj2(get_random(type));
    test_obj2.print();
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (start)...\n";
        test_obj2.push_start(get_random(type));
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
    }
    for (int i = 0; i < 3; i++) {
        cout << "Adding next element (end)...\n";
        test_obj2.push_end(get_random(type));
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
    }
    cout << "Peeked at element ";
    print_data(test_obj2.peek_start());
    cout << " (start)\n";
    cout << "Peeked at element ";
    print_data(test_obj2.peek_end());
    cout << " (end)\n";
    for (int i = 0; i < 3; i++) {
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
        cout << "Popped element ";
        print_data(test_obj2.pop_start());
        cout << " (start)\n";
        cout << "Current structure: ";
        test_obj2.print();
        cout << "Current structure (reversed): ";
        test_obj2.print_rev();
        cout << "Popped element ";
        print_data(test_obj2.pop_end());
        cout << " (end)\n";
    }
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    cout << "Filling with random elements...\n";
    test_obj2.fill_random(10);
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    cout << "Filling with random elements...\n";
    test_obj2.fill_random(10);
    cout << "Current structure: ";
    test_obj2.print();
    cout << "Current structure (reversed): ";
    test_obj2.print_rev();
    */
    
    
    return 0;
}

