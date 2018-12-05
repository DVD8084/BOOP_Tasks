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

#include "dice.cpp"
#include "empty.cpp"
#include "random.cpp"
#include "print.cpp"
#include "lists.cpp"
#include "arrays.cpp"
#include "std.cpp"
#include "test.cpp"

/*
 * 
 */


int main(int argc, char** argv)
{
    /* Possible vaues for structure_test():
     * STACK, QUEUE, DEQUE for the second argument;
     * ARRAY, LIST, STDLIB for the third argument.
     */
    int type;
    //structure_test(type, DEQUE, STDLIB);
    dice_test();
    return 0;
}

