//
//  Queue.h
//  Tree
//
//  Created by Sutej Kulkarni on 03/08/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    struct tree_node *lchild;
    int data;
    struct tree_node *rchild;
};

struct qu
{
    int size;
    int front;
    int rear;
    struct tree_node **q;
};

void create_queue(struct qu *pq,int size1)
{
    pq->size = size1;
    pq->front = pq->rear = 0;
    pq->q = (struct tree_node**)malloc(size1 * sizeof(struct tree_node *));
}

int isEmpty(struct qu s)
{
    if(s.front == s.rear)
    {
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

int isFull(struct qu s1)
{
    if(s1.front == (s1.rear+1)%s1.size)
    {
        printf("Queue is Full\n");
        return 1;
    }
    return 0;
}

void enqueue(struct qu *q2,struct tree_node *p)
{
    if(isFull(*q2))
    {
        printf("Queue is full\n");
        return;
    }
    
    q2->rear = (q2->rear + 1) % q2->size;
    q2->q[q2->rear] = p;
}

struct tree_node* dequeue(struct qu *q4)
{
    //int x=-1;
    struct tree_node *q = NULL;
    if(isEmpty(*q4))
    {
        printf("Queue is empty\n");
        return NULL;
    }
   
    q4->front = (q4->front + 1) % q4->size;
    q = q4->q[q4->front];
    printf("Dequeued value is %p\n",q);
    return q;
}

#endif /* Queue_h */
