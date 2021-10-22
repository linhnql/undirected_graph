#include <stdio.h>
#include "queue.h"

queue* create_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q -> pFront = q -> pRear = NULL;
    return q;
}

void enqueue(queue* q, int k){
    que_node* temp = (que_node*)malloc(sizeof(que_node));
    temp -> key = k;
    temp -> next = NULL;

    if (q -> pRear == NULL) {
        q -> pFront = q -> pRear = temp;
        return;
    }

    q -> pRear -> next = temp;
    q -> pRear = temp;
}

int dequeue(queue* q){
    if (q -> pFront == NULL) return;

    que_node* temp = q -> pFront;
    q -> pFront = q -> pFront -> next;

    if (q -> pFront == NULL) q -> pRear = NULL;
    int front = temp -> key;
    free(temp);
    return front;
}

int q_empty(queue* q){
    return (q -> pRear == NULL);
}

void print_queue(queue* q){
    que_node* temp = q -> pFront;
    while (temp){
        printf("%d ", temp -> key);
        temp = temp -> next;
    }
}
