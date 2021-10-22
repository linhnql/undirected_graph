#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct que_node {
    int key;
    struct que_node* next;
};
typedef struct que_node que_node;

struct queue {
    que_node *pFront, *pRear;
};
typedef struct queue queue;

queue* create_queue();
void enqueue(queue*, int);
int dequeue(queue*);
int q_empty(queue*);
void print_queue(queue*);

#endif // QUEUE_H_INCLUDED
