/* 
 * File:   stack.h
 * Author: mike meding
 *
 * Created on October 7, 2013, 1:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define	STACK_H

#ifdef	__cplusplus
extern "C" {
#endif

   typedef struct Node {
	  StackData data;
	  struct Node *next;
   } Node, *NodePtr;

   typedef struct stackType {
	  NodePtr top;
   } StackType, *Stack;



   /*PROTOTYPES*/
   void push(Stack stack, StackData data);

   StackData pop(Stack stack);

   StackData peek(Stack stack);

   Stack initStack(void);

   void empty(Stack stack);

   bool isEmpty(Stack stack);

   /////////////////////////////////////////////

   /* create a new and empty stack */
   Stack initStack(void) {
	  Stack sp = (Stack) malloc(sizeof (StackType)); // allocate memory to 
	  sp -> top = NULL;
	  return sp;
   }

   /* function will push a new value given by StackData to the stack*/
   void push(Stack stack, StackData data) {
	  NodePtr np = (NodePtr) malloc(sizeof (Node));
	  np ->data = data;
	  np ->next = stack->top;
	  stack ->top = np;
   }

   /* will pop the top value off of the stack */
   StackData pop(Stack stack) {
	  StackData temp = malloc(sizeof (StackData));
	  if (isEmpty(stack)) { // if stack is empty.
		 temp->error = true; // as this is the error case
		 temp->i = stack->top->data->i;
		 return temp;
	  } else { // if no error is found
		 NodePtr nodeTemp = stack ->top; // create temp of the head node
		 temp->i = stack->top->data->i; // set the data to be returned
		 temp->error = false; // set error code again to be sure.
		 stack->top = stack->top->next; // move stack to the next value down
		 free(nodeTemp); // free the previous head node
		 return temp;
	  }

   }

   StackData peek(Stack stack) {
	  return stack->top->data;
   }

   /* clear entire stack */
   void empty(Stack stack) {
	  stack->top = NULL;
   }

   /* function will return true if there are no values in stack */
   bool isEmpty(Stack stack) {
	  if (stack ->top == NULL) {
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

#endif	/* STACK_H */

