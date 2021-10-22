#include <stdio.h>
#include "stack.h"

void creat(){
    pTop = NULL;
}

void push(int data){
    st_node* temp = (st_node*)malloc(sizeof(st_node));

    if (!temp){
        printf("\nHeap Overflow");
        exit(1);
    }
    temp -> data = data;
    temp -> prev = pTop;
    pTop = temp;
}

void pop(){
    st_node* temp;

    if (pTop == NULL){
        printf("\nStack Underflow");
        exit(1);
    }else{
        temp = pTop;
        pTop = pTop -> prev;
        temp -> prev = NULL;
        free(temp);
    }
}

int st_empty(){
    return pTop == NULL;
}

void print_stack(){
    st_node* temp;

    if (pTop == NULL){
        printf("\nStack Underflow");
        exit(1);
    }else{
        temp = pTop;
        while (temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> prev;
        }
    }
}

