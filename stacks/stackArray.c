/* 
 * File:   main.c
 * Author: Roy Van Liew
 *
 * Created on October 7, 2013, 1:04 PM
 */

/* IMPORTANT: the second case does not work with the parentheses in the middle of the bracket.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This is interchangeable depending on what datatype is needed.

#include "stackL.h"
//#include "stackA.h"

#define MAXFILESIZE 100

int main(int argc, char** argv) {

    // input from a file
    FILE *ptr_file;
    char buffer[MAXFILESIZE];

    Stack stack = initStack(); // initalize stack
    empty(stack); // ensure its empty

    int y = 0;

    ptr_file = fopen("expressions.txt", "r");
    if (!ptr_file) { // if error is encountered or file does not exist
        return 1;
    } else { // if no error is encountered
        while (fgets(buffer, MAXFILESIZE, ptr_file) != NULL) { // get 1 line at a time

            printf("%s", buffer); // print the line for good measure
            y = 0; // reset line position counter
            while (buffer[y] != '\n') { // loop over all the values of the current line
                // do not define things within a switch case. compiler will argue with you
                StackData temp = malloc(sizeof (StackData)); // you need to allocate the memory for each new value
                StackData peekstuff = malloc(sizeof (StackData)); // you need to allocate the memory for each new value
                switch (buffer[y]) { // switch for each char in the line
                    case '{':
                    case '[':
                    case '(':
                        // set values.
                        temp->i = buffer[y];
                        temp->error = false;
                        push(stack, temp); // push data to stack
                        printf("Pushed opening delimiter '%c'\n", temp->i);
                        break;

                    case '}':
                    case ']':
                    case ')':
                        
                        temp = pop(stack);
                        if (buffer[y] == ']' && temp->i != '[')
                            printf("Closing square bracket not preceded by opening square bracket.\n");
                        if (buffer[y] == ')' && temp->i != '(')
                            printf("Closing parentheses not preceded by opening parentheses.\n");
                        if (buffer[y] == '}' && temp->i != '{')
                            printf("Closing bracket not preceded by opening bracket.\n");
                        if (buffer[y] == ']' && temp->i == '[')
                            printf("Found matching square brackets '[]'.\n");
                        if (buffer[y] == ')' && temp->i == '(')
                            printf("Found matching parentheses '()'.\n");
                        if (buffer[y] == '}' && temp->i == '{')
                            printf("Found matching brackets '{}'.\n");                       
                        if (temp->error) {
                            printf("Stack contains '%c'. Missing opening argument.\n", buffer[y]);
                        }
                        break;

                        /*
                        peekstuff = peek(stack);
                        if( peekstuff->i == '(' && buffer[y] != ')' ){
                            printf("Found closing parentheses, but it is not preceded by a open parentheses (\n");
                        }
                        if( peekstuff->i == '[' && buffer[y] != ']' ){
                            printf("Found closing square bracket, but it is not preceded by a open square bracket\n");
                        }
                        if( peekstuff->i == '{' && buffer[y] != '}' ){
                            printf("Found closing bracket, but it is not preceded by a open bracket\n");
                        }                        
                        temp = pop(stack);                        
                        break;
                        */ 

                }
                y++;
            }

            if (!isEmpty(stack)) { // if the stack is NOT empty 
                printf("Stack contains '%c'. Missing closing argument.\n\n", peek(stack)->i);
                empty(stack);
            } else {
                printf("\n\n"); // too keep with the line pattern.
            }



        } // loops to next line in file
    }


    // push all matching symbols to the stack
    // pop all matching symbols from the stack 
    // print what remains at the end of the line
    // empty stack
    // repeat for all lines in file.


    fclose(ptr_file);

    return (EXIT_SUCCESS);
}

