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

    
    /*LINKED LIST STRUCTURE*/
    typedef struct Element {
        StackData *data;
        struct Element *next;
    } Element;

    /*PROTOTYPES*/
    int push(Element **stack, int *data);

    StackData pop(Element **stack, int **data);
    
    StackData peek(Element **stack);

    int initStack(Element **stack);

    int empty(Element **stack);

    bool isEmpty(Element **stack);

    ////////////////////////////

    int initStack(Element **stack) {
        *stack = NULL;
        return 0;
    }

    int push(Element **stack, StackData *data) {
        Element *elem;
        elem = (Element*) malloc(sizeof (Element*));
        if (!elem) return 1;

        elem->data->i = data->i;
        elem->next = *stack;
        *stack = elem;
        return 0;
    }

    StackData pop(Element **stack, StackData **data) {
        Element *elem;
        elem = *stack;
        if (!elem) return 1;

        *stack = elem->next;
        *data->i = (elem->data->i);
        free(elem);
        return *data->i;
    }
    
    StackData peek(Element **stack){
        
    }

    int empty(Element **stack) {
        Element *next;

        while (*stack) {
            next = (*stack)->next;
            free(*stack);
            *stack = next;
        }
        return 0;
    }

    bool isEmpty(Element **stack) {
        if (*stack == NULL) {
            return false; // stack is NULL = no values
        } else {
            return true; // stack has values other than NULL
        }
    }
    
    void display(Element **stack){
        Element *temp = stack;
        Element *next;
        while(*temp){           
            &next = (*temp)->next;
            pop(&temp, &temp->data);
            *temp = next;           
        }
    }



#ifdef	__cplusplus
}
#endif

#endif	/* STACK_H */

