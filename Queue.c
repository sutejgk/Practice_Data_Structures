//
//  Queue.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 30/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct my_q
{
    int size;
    int front;
    int rear;
    int *q;
};

void create_queue(struct my_q *q1)
{
    printf("Enter the size of the queue:\n");
    scanf("%d",&q1->size);;
    q1->front = q1->rear = -1;
    q1->q = (int *)malloc(q1->size * sizeof(int));
}

void display(struct my_q sl)
{
    int i = 0;
    if(sl.rear == -1)
        return;
    for(i = sl.front+1;i<=sl.rear;i++)
    {
        printf("%d\n",sl.q[i]);
    }
    printf("\n");
}

int isEmpty(struct my_q pq)
{
    if(pq.front == pq.rear)
        return 1;
    return 0;
}

int isFull(struct my_q pq1)
{
    if(pq1.rear == pq1.size - 1)
        return 1;
    return 0;
}

void enqueue(struct my_q *q2, int data)
{
    if(isFull(*q2))
    {
        printf("Queue is full\n");
        return;
    }
    
    q2->rear = q2->rear + 1;
    q2->q[q2->rear] = data;
}

int dequeue(struct my_q *q4)
{
    int x = -1;
    if(isEmpty(*q4))
    {
        printf("Queue is full\n");
        return x;
    }
    
    q4->front = q4->front + 1;
    x = q4->q[q4->front];
    return x;
}

int last(struct my_q s)
{
    if(s.rear == -1)
    {
        printf("No elements in the queue:\n");
        return -1;
    }
    
    printf("Last elements in the queue is %d\n",s.q[s.rear]);
    return s.q[s.rear];
}

int first(struct my_q s1)
{
    int x = 0;
    if(s1.rear == -1)
    {
       printf("No elements in the queue:\n");
        return -1;
    }
    
    s1.front = s1.front + 1;
    x = s1.q[s1.front];
    printf("First element of the queue is %d\n",x);
    s1.front = s1.front - 1;
    return x;
}

int main()
{
    struct my_q q1;
    
    create_queue(&q1);
    isEmpty(q1);
    enqueue(&q1, 5);
    enqueue(&q1, 6);
    enqueue(&q1, 7);
    enqueue(&q1, 8);
    enqueue(&q1, 9);
    isFull(q1);
    
    display(q1);
    
    dequeue(&q1);
    dequeue(&q1);
    
    display(q1);


    first(q1);
    last(q1);

    
    return 0;
}
