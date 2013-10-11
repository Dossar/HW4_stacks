/* 
 * File:   main.c
 * Author: mike
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
} *StackData;

#include "stackL.h"

#define MAXFILESIZE 100

int main(int argc, char** argv) {


   // test out shitty stack.h functions here


   // input from a file
   FILE *ptr_file;
   char buffer[MAXFILESIZE];


   ptr_file = fopen("expressions.txt", "r");
   if (!ptr_file) { // if error is encountered or file does not exist
	  return 1;
   } else { // if no error is encountered
	  while (fgets(buffer, MAXFILESIZE, ptr_file) != NULL) { // get the entire file and put it into an array.
		 printf("%s", buffer); // print out entire file which is stored in buffer
	  }
   }

   // tokenize the input of the file into lines
   // push all matching symbols to the stack
   // pop all matching symbols from the stack 
   // print what remains at the end of the line
   // empty stack
   // repeat for all lines in file.
   int value  = 5;
   
   StackData someData;
   someData->i = value;
   someData->error = false;

   Stack stack = initStack();
   empty(stack);
   push(stack, someData);
   someData->i = value;
   push(stack, someData);
   someData = pop(stack);

   printf("popped value = %d", someData->i);





   fclose(ptr_file);
   return (EXIT_SUCCESS);
}

