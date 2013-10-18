/* 
 * File:   stackA.h
 * Author: Roy Van Liew
 *
 * Created on October 9, 2013, 10:08 AM
 */

#ifndef STACKA_H
#define	STACKA_H

#ifdef	__cplusplus
extern "C" {
#endif

    // Side note: "MaxStack" will be a defined value in the c program to state the max size of the stack.

#define MaxStack 100

    typedef struct stackType {
        int top; // For the index of top stack element
        StackData SD[MaxStack]; // Array of the stack elements
    } StackType, *Stack;

    /*PROTOTYPES*/
    void push(Stack stack, StackData data);

    StackData pop(Stack stack);

    StackData peek(Stack stack);

    Stack initStack(void);

    void empty(Stack stack);

    bool isEmpty(Stack stack);

    /* ARRAY STACK FUNCTIONS */

    /* create a new and empty stack */
    Stack initStack(void) {
        Stack sp = (Stack) malloc(sizeof (StackType)); // stack pointer
        sp->top = -1; // When initializing, set the top of the stack so when we get into the push function the +1 makes the index 0.
        return sp; // Return the pointer to the stack.
    }

    /* function will push a new value given by StackData to the stack*/
    void push(Stack stack, StackData data) {

        // This if statement checks if the attay stack is already full.
        if (stack->top == MaxStack - 1) {
            /* No more space in the stack when top has value (MaxStack - 1)
               MaxStack is defined within the c program */
            exit(1);
        }
        ++(stack->top); // Getting to this point means the stack wasn't full. Add 1 to stack->top to keep track of the top of the stack.
        stack->SD[stack->top] = data; // Saves new value into the top element of the stack, into the SD array.

    }

    /* will pop the top value off of the stack */
    StackData pop(Stack stack) {

        StackData temp = malloc(sizeof (StackData));
        if (isEmpty(stack)) { // if stack is empty.
            temp->error = true; // as this is the error case
            temp->i = 0;
            return temp;
        } else {
            temp->i = stack->SD[stack->top]->i; // set the data to be returned
            temp->error = false; // set error code again to be sure.
            --(stack->top); // Make the top position of the stack one less.
            return temp; // Return the popped element's value.
        }
    }

    /* Returns the value current at the head of the stack without removing it
       In the case of an area, the top index is the last array element */
    StackData peek(Stack stack) {
        return stack->SD[stack->top];
    }

    /* Clear entire stack */
    void empty(Stack stack) {

        // This while loop continuously calls pop until the top index reaches -1.
        while (stack->top != -1)
            pop(stack);
    }

    /* function will return true if there are no values in stack */
    bool isEmpty(Stack stack) {

        // If top is -1, the stack is empty. The array has just been initialized or it has been cleaned.
        if (stack->top == -1) {
            return true;
        } else {
            return false;
        }

    }

    void display(Stack stack) {
        /* Nothing here for now */
    }




#ifdef	__cplusplus
}
#endif

#endif	/* STACKA_H */

