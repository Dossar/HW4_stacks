/* 
 * File:   stackTest.c
 * Author: Roy Van Liew and Mike Meding
 *
 * Created on October 7, 2013, 1:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This is interchangeable depending on what datatype is needed.

typedef struct {
    int i;
    bool error; // instead of having a rouge value use error codes
} Data, *StackData;

#include "stackL.h"
//#include "stackA.h"

#define MAXFILESIZE 100

int main(int argc, char** argv) {

    Stack testStack = initStack(); //Initialize S as a pointer to a stack.
    printf("The stack has been initialized.\n");
    
    if( isEmpty(testStack) )
        printf("The stack is currently empty.\n");
    else
        printf("The stack is not empty.\n");
    // Push three randomly generated integers into the stack
    int s = 0;
    while( s < 3 )
    {
        StackData numinput = malloc(sizeof (StackData));
        numinput->i = rand()%1000;
        push(testStack, numinput);
        printf("%d has been added to the stack.\n", numinput->i);
        s++; 
    }
    if (isEmpty(testStack))
        printf("The stack is currently empty.\n");
    else
        printf("The stack is not empty.\n");
    printf("The top element of the stack is %d.\n", (peek(testStack))->i);
    printf("Now emptying the stack.\n");
    while(!isEmpty(testStack))
        printf("%d has been popped from the stack.\n", (pop(testStack))->i);
    if (isEmpty(testStack))
        printf("The stack is currently empty.\n");
    else
        printf("The stack is not empty.\n");
    
    

    return (EXIT_SUCCESS);
}

