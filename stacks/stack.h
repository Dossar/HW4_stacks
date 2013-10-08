/* 
 * File:   stack.h
 * Author: mike
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

    //    typedef struct Node {
    //        StackData data;
    //        Node *next;
    //    } *top, base;
    //    
    //
    //    void initStack(Node *s) {
    //        top = NULL;
    //    }
    //    
    //    
    //    void empty(Node *s){
    //        while(top != NULL){
    //            pop(s);
    //        }
    //    }
    //    
    //    bool isEmpty(Node *s){
    //        if(s->next == top || s != NULL){
    //            return true; // if stack contains values
    //        } else {
    //            return false; // if stack is empty
    //        }
    //    }
    //    
    //    
    //    void push(Node *temp, StackData d){
    //        if (top == NULL) {
    //            top = temp;
    //            temp->data = d;
    //            top->next = NULL;
    //        } else {
    //            temp->next = top;
    //            top = temp;
    //        }
    //    }
    //    
    //    StackData pop(Node *s){
    //        Node *var = top;
    //        if (var == top) {
    //            top = top->next;
    //            free(var);
    //        } else
    //            printf("\nStack Empty");
    //    }
    //    
    //    StackData peek(Node *s);
    //    
    //    
    //    void display() {
    //        struct Node *var = top;
    //        if (var != NULL) {
    //            printf("\nElements are as:\n");
    //            while (var != NULL) {
    //                printf("\t%d\n", var->Data);
    //                var = var->next;
    //            }
    //            printf("\n");
    //        } else
    //            printf("\nStack is Empty");
    //    }

    typedef struct Element {
        int *data;
        struct Element *next;
    } Element;

    int push(Element **stack, int *data);

    int pop(Element **stack, int **data);

    int createStack(Element **stack);

    int deleteStack(Element **stack);

    ////////////////////////////

    int createStack(Element **stack) {
        *stack = NULL;
        return 0;
    }

    int push(Element **stack, int *data) {
        Element *elem;
        elem = (Element*) malloc(sizeof (Element*));
        if (!elem) return 1;

        elem->data = data;
        elem->next = *stack;
        *stack = elem;
        return 0;
    }

    int pop(Element **stack, int **data) {
        Element *elem;
        elem = *stack;
        if (!elem) return 1;

        *stack = elem->next;
        *data = (elem->data);
        free(elem);
        return 0;
    }

    int deleteStack(Element **stack) {
        Element *next;

        while (*stack) {
            next = (*stack)->next;
            free(*stack);
            *stack = next;
        }
        return 0;
    }



#ifdef	__cplusplus
}
#endif

#endif	/* STACK_H */

