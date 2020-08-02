//
//  Circular_Queue.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 30/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct qu
{
    int size;
    int front;
    int rear;
    int *q;
};

void create_queue(struct qu *pq,int size1)
{
    pq->size = size1;
    pq->front = pq->rear = 0;
    pq->q = (int*)malloc(size1 * sizeof(int));
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

void enqueue(struct qu *q2,int element)
{
    if(isFull(*q2))
    {
        printf("Queue is full\n");
        return;
    }
    
    q2->rear = (q2->rear + 1) % q2->size;
    q2->q[q2->rear] = element;
}

int dequeue(struct qu *q4)
{
    int x=-1;
    if(isEmpty(*q4))
    {
        printf("Queue is empty\n");
        return x;
    }
   
    q4->front = (q4->front + 1) % q4->size;
    x = q4->q[q4->front];
    printf("Dequeued value is %d\n",x);
    return x;
}

void display(struct qu q6)
{
    int i = q6.front+1;
    do
    {
        printf("%d ",q6.q[i]);
        i = (i+1)%(q6.size);
    }while(i!=(q6.rear+1)%q6.size);
    printf("\n");
}

void first(struct qu q8)
{
    q8.front = q8.front+1;
    printf("First element in the queue is : %d\n",q8.q[q8.front]);
}

void last(struct qu q10)
{
    printf("Last element in the queue is : %d\n",q10.q[q10.rear]);
}

int main()
{
    struct qu my_q;
    
    create_queue(&my_q, 5);
    
    isEmpty(my_q);
    
    enqueue(&my_q, 3);
    enqueue(&my_q, 6);
    enqueue(&my_q, 9);
    enqueue(&my_q, 12);
    enqueue(&my_q, 15);
    
    //isFull(my_q);
    
    display(my_q);
    
    dequeue(&my_q);
    dequeue(&my_q);

    dequeue(&my_q);
    display(my_q);

    first(my_q);
    last(my_q);
    enqueue(&my_q, 15);
    enqueue(&my_q, 17);
    enqueue(&my_q, 19);
    enqueue(&my_q, 21);
    
    display(my_q);


    first(my_q);
    last(my_q);
    
    return 0;

}
