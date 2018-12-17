#include "print.h"

using std::cout;

/**
 *  These functions are used to print the data for any supported data type.
 */

void print_data(int data)
{
    cout << data;
}

void print_data(float data)
{
    cout << data;
}

void print_data(double data)
{
    cout << data;
}

void print_data(char data)
{
    cout << data;
}

void print_data(std::string data)
{
    cout << data;
}

void print_data(Dice data)
{
    cout << "D" << data.side_amount() << "[";
    for (int i = 0; i < data.side_amount(); i++) {
        cout << "P(" << i << ") = " << data.probability(i);
        if (i < data.side_amount() - 1)
        {
            cout << "; ";
        }
    }
    cout << "]";
}