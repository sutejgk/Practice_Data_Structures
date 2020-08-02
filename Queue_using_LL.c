//
//  Queue_using_LL.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 31/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int data;
    struct sll *next;
};

struct sll *front = NULL;
struct sll *rear = NULL;

void enqueue(int element)
{
    struct sll *t = NULL;
    t = (struct sll*)malloc(sizeof(struct sll));
    if(t==NULL)
    {
        printf("Queue is Full\n");
        return;
    }
    t->data = element;
    t->next = NULL;
    if(front == NULL)
    {
        front = rear=t;
        return;
    }
    rear->next = t;
    rear = t;
}

int dequeue()
{
    int x=-1;
    struct sll *p = NULL;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return x;
    }
    
    p=front;
    if(front->next == NULL)
    {
        x = p->data;
        free(p);
        return x;
    }
    
    front = front->next;
    x = p->data;
    free(p);
    return x;
}

void Display(struct sll *s)
{
    s = front;
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s= s->next;
    }
    printf("\n");
}

void first()
{
    printf("First element is: %d\n",front->data);
}

void last()
{
    printf("Last element is: %d\n",rear->data);
}

int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(100);
    
    Display(front);
    
    first();
    last();
    
    dequeue();
    dequeue();
    dequeue();
    
    Display(front);
    
    first();
    last();

    enqueue(200);
    
    Display(front);
    
    first();
    last();

    return 0;
}


