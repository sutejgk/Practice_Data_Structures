//
//  stack_using_LL.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 28/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct sll_node
{
    int data;
    struct sll_node *next;
};

struct sll_node *p_top = NULL;

void push(int data1)
{
    struct sll_node *p1=NULL;
    
    p1 = (struct sll_node*)malloc(sizeof(struct sll_node));
    if(p1==NULL)
    {
        printf("\nStack overflow!\n");
        return ;
    }
    p1->data  = data1;
    p1->next = NULL;
    
    
    
    if(p_top == NULL)
    {
        p_top = p1;
        return;
    }
    
    p1->next = p_top;
    p_top = p1;
}

int pop()
{
    int x  = -1;
    if(p_top == NULL)
    {
        printf("\nStack Underflow\n");
        return x;
    }
    struct sll_node *t;
    t = p_top;
    x = t->data;
    p_top = p_top->next;
    free(t);
    printf("\nPopped value is: %d\n",x);
    return x;
}

void display(struct sll_node *q)
{
    while(q!=NULL)
    {
        printf("%d\n", q->data);
        q = q->next;
    }
}

void isEmpty()
{
    if(p_top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
}

void isFull()
{
    struct sll_node *p= NULL;
    p = (struct sll_node*)malloc(sizeof(struct sll_node));
    if(p==NULL)
        printf("Stack is Full\n");
    else
        printf("Stack is not full\n");
    free(p);
    
}

int StackTop()
{
    int x = -1;
    if(p_top == NULL)
    {
        printf("Stack is empty\n");
        return x;
    }
    x = p_top->data;
    printf("Element at the top of the stack is: %d\n", p_top->data);
    return x;
}

int peek(int pos)
{
    struct sll_node *q;
    int i =1;
    int x=-1;
    q = p_top;
    
    if(q == NULL)
    {
        printf("Stack is Empty\n");
        return x;
    }
    
    for(i=1;q!=NULL && i<=pos-1;i++)
    {
        q = q->next;
    }
    
    if(q==NULL)
    {
        printf("Invalid Position\n");
        return x;
    }
    
    x = q->data;
    printf("Element at pos %d is %d\n",pos,x);
    return x;
}

int main()
{

    return 0;
}
