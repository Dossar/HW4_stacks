//
///* 
// * File:   main.c
// * Author: Roy Van Liew
// *
// * Created on October 16, 2013, 6:49 AM
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//// This is interchangeable depending on what datatype is needed.
//
//typedef struct {
//    char i;
//    bool error; // instead of having a rouge value use error codes
//} Data, *StackData;
//
//// MaxStack defines 100 as the maximum array stack size.
//#define MaxStack 100
//
//#include "stackA.h"
//
//
//#define MAXFILESIZE 100
//
//int main(int argc, char** argv) { // you cannot have two main functions in code.
//    // I call second_main at the end of main in stackTest.c
//
//    // input from a file
//    FILE *ptr_file;
//    char buffer[MAXFILESIZE];
//
//    Stack stack = initStack(); // initalize stack
//    empty(stack); // ensure its empty
//
//    int y = 0;
//
//    ptr_file = fopen("expressions.txt", "r"); // Open txt file in read mode
//    if (!ptr_file) { // if error is encountered or file does not exist
//        return 1;
//    } else { // if no error is encountered
//        while (fgets(buffer, MAXFILESIZE, ptr_file) != NULL) { // get 1 line at a time
//
//            printf("%s", buffer); // print the line for good measure
//            y = 0; // reset line position counter
//            while (buffer[y] != '\n') { // loop over all the values while the character is not a newline
//                // do not define things within a switch case. compiler will argue with you
//                // StackData temp = malloc(sizeof (StackData)); <- This is for nodes, not array
//                StackData temp; // This is for the case of a closing delimiter.
//                switch (buffer[y]) { // switch for each char in the line
//                    case '{':
//                    case '[':
//                    case '(':
//                        stack->SD[y] = buffer[y]; // Fill the stack with the opening delimiters of the buffer
//                        push(stack, temp); // push data to stack
//                        printf("Pushed '%c' to the stack\n", stack->SD[y]); // This may have to be changed in the event of a stack overflow.
//                        break;
//
//                    /* For closing delimiters, we're going to call pop instead of push */
//                    case '}':
//                    case ']':
//                    case ')':
//                        temp = pop(stack); // temp here stores the top element of the stack
//                        if ( isEmpty(stack) ) {
//                            printf("Stack pop error\n"); // Means stack is empty
//                        } else {
//                            printf("Popped '%c'.\n", temp);
//                        }
//                        break;
//
//                }
//                y++; // Proceed to the next item in the buffer. This will continue until a newline is reached.
//            }
//        }
//    }
//
//
//    // push all matching symbols to the stack
//    // pop all matching symbols from the stack 
//    // print what remains at the end of the line
//    // empty stack
//    // repeat for all lines in file.
//
//
//
//
//
//
//
//    //    int x = 0;
//    //    for (x = 0; x < 10; x++) {
//    //        StackData temp = malloc(sizeof (StackData)); // you need to allocate the memory for each new value
//    //        temp ->i = x; // set values.
//    //        temp ->error = false;
//    //        push(stack, temp);
//    //    }
//    //
//    //    while (!temp->error) {
//    //        temp = pop(stack);
//    //        printf("popped value = %d\n", temp->i);
//    //    }
//    //
//    //    StackData temp2 = peek(stack);
//    //    printf("peeked value = %d\n", temp2->i);
//
//
//
//    fclose(ptr_file);
//    return (EXIT_SUCCESS);
//}
//
