#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct st_node {
    int data;
    struct st_node* prev;
}*pTop;
typedef struct st_node st_node;

void creat();
void push(int);
void pop();
int st_empty();
void print_stack();


#endif // STACK_H_INCLUDED
