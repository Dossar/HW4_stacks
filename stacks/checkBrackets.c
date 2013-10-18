/* 
 * File:   main.c
 * Author: Roy Van Liew and Mike Meding
 *
 * Created on October 7, 2013, 1:04 PM
 */

/* IMPORTANT: the second case does not work with the parentheses in the middle of the bracket.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This is interchangeable depending on what datatype is needed.

typedef struct {
    char i;
    bool error; // instead of having a rouge value use error codes
} Data, *StackData;

#include "stackL.h"
//#include "stackA.h"

#define MAXFILESIZE 100

//PROTOTYPES
bool checkBalanced(char*);
bool isPaired(char, char);

int main(int argc, char** argv) {

    // input from a file
    FILE *ptr_file;
    char buffer[MAXFILESIZE];

    ptr_file = fopen("expressions.txt", "r");
    if (!ptr_file) { // if error is encountered or file does not exist
        return 1;
    } else { // if no error is encountered
        while (fgets(buffer, MAXFILESIZE, ptr_file) != NULL) { // get 1 line at a time

            if (checkBalanced(buffer)) {
                printf("STATEMENT IS TRUE\n\n");
            } else {
                printf("STATEMENT IS FALSE\n\n");
            }

            //            printf("%s", buffer); // print the line for good measure
            //            y = 0; // reset line position counter
            //            while (buffer[y] != '\n') { // loop over all the values of the current line
            //                // do not define things within a switch case. compiler will argue with you
            //                StackData temp = malloc(sizeof (StackData)); // you need to allocate the memory for each new value
            //                StackData peekstuff = malloc(sizeof (StackData)); // you need to allocate the memory for each new value
            //                switch (buffer[y]) { // switch for each char in the line
            //                    case '{':
            //                    case '[':
            //                    case '(':
            //                        // set values.
            //                        temp->i = buffer[y];
            //                        temp->error = false;
            //                        push(stack, temp); // push data to stack
            //                        printf("Pushed opening delimiter '%c'\n", temp->i);
            //                        break;
            //
            //                    case '}':
            //                    case ']':
            //                    case ')':
            //
            //                        temp = pop(stack);
            //                        if (buffer[y] == ']' && temp->i != '[')
            //                            printf("Closing square bracket not preceded by opening square bracket.\n");
            //                        if (buffer[y] == ')' && temp->i != '(')
            //                            printf("Closing parentheses not preceded by opening parentheses.\n");
            //                        if (buffer[y] == '}' && temp->i != '{')
            //                            printf("Closing bracket not preceded by opening bracket.\n");
            //                        if (buffer[y] == ']' && temp->i == '[')
            //                            printf("Found matching square brackets '[]'.\n");
            //                        if (buffer[y] == ')' && temp->i == '(')
            //                            printf("Found matching parentheses '()'.\n");
            //                        if (buffer[y] == '}' && temp->i == '{')
            //                            printf("Found matching brackets '{}'.\n");
            //                        if (temp->error) {
            //                            printf("Stack contains '%c'. Missing opening argument.\n", buffer[y]);
            //                        }
            //                        break;
            //
            //                  
            //
            //                }
            //                y++;
            //            }
            //
            //            if (!isEmpty(stack)) { // if the stack is NOT empty 
            //                printf("Stack contains '%c'. Missing closing argument.\n\n", peek(stack)->i);
            //                empty(stack);
            //            } else {
            //                printf("\n\n"); // too keep with the line pattern.
            //            }
            //


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

bool checkBalanced(char* buffer) {
    // VARIABLES
    Stack stack = initStack(); // initalize stack
    empty(stack); // ensure its empty
    int y = 0; // line position counter
    bool endValue = true; // assume line is true until proven false
    bool pairValue = true;

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
                if (temp->error) {
                    printf("Stack contains '%c'. Missing opening argument.\n\n", buffer[y]);
                    return false;
                } else {
                    if(!isPaired(temp->i, buffer[y])){
                        pairValue = false;
                    }
                }

                break;



        }
        y++;
    }

    if (!isEmpty(stack)) { // if the stack is NOT empty 
        printf("Stack contains '%c'. Missing closing argument.\n\n", peek(stack)->i);
        empty(stack);
        return false;

    } else {
        printf("\n"); // too keep with the line pattern.
        if (!pairValue) {
            return false;
        } else {
            return true;
        }

    }


}

bool isPaired(char openBracket, char closeBracket) {
    if (closeBracket == ']' && openBracket != '[') {
        printf("Closing square bracket not preceded by opening square bracket.\n");
        return false;
    }
    if (closeBracket == ')' && openBracket != '(') {
        printf("Closing parentheses not preceded by opening parentheses.\n");
        return false;
    }
    if (closeBracket == '}' && openBracket != '{') {
        printf("Closing bracket not preceded by opening bracket.\n");
        return false;
    }
    if (closeBracket == ']' && openBracket == '[') {
        printf("Found matching square brackets '[]'.\n");
        return true;
    }
    if (closeBracket == ')' && openBracket == '(') {
        printf("Found matching parentheses '()'.\n");
        return true;
    }
    if (closeBracket == '}' && openBracket == '{') {
        printf("Found matching brackets '{}'.\n");
        return true;
    }

}

