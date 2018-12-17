#include "arrays.h"
#include "dice.h"
#include "empty.h"
#include "lists.h"
#include "print.h"
#include "random.h"
#include "std.h"
#include "test.h"

int main(int argc, char** argv)
{
    /* 
     * Possible vaues for structure_test():
     * STACK, QUEUE, DEQUE for the second argument;
     * ARRAY, LIST, STDLIB for the third argument.
     */
    char type;
    structure_test(type, QUEUE, LIST);
    //dice_test();
    return 0;
}

