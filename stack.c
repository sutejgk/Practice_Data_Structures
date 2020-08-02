//
//  stack.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 26/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter the size of the stack:\n");
    scanf("%d",&st->size);
    st->top = -1;
    
    //correct arguement for malloc, is this 5 bytes or 5 integers?
    st->s = (int*)malloc(st->size * sizeof(int));
}

//Call by value, since we are not modifying anything
void Display(struct stack p2)
{
    int i = 0;
    for(i=p2.top;i>-1;i--)
    {
        printf("%d\n",p2.s[i]);
    }
}

int isEmpty(struct stack p1)
{
    if(p1.top == -1)
    {
        printf("\nStack is empty\n");
        return 1;
    }
    return 0;
}

int isFull(struct stack q1)
{
    if(q1.top == q1.size-1)
    {
        printf("\nStack is full\n");
        return 1;
    }
    
    return 0;
}

void push(struct stack *p, int data)
{
    //Check whether stack is already full
    
    if(isFull(*p))
    {
        printf("\nStack Overflow\n");
        return;
    }
    
    p->top = p->top + 1;
    p->s[p->top] = data;
}

int pop(struct stack *q)
{
    //Check if stack is empty
    int x = -1;
    if(isEmpty(*q))
    {
        printf("\nStack Underflow\n");
        return x;
    }
    
    x = q->s[q->top];
    q->top = q->top - 1;
    printf("\nPopped value is %d\n",x);
    return x;
}

int StackTop(struct stack r)
{
    if(r.top == -1)
    {
        printf("\nNo elements in stack\n");
        return -1;
    }
    printf("\nElement at the top of the stack is %d\n",r.s[r.top]);
    return r.s[r.top];
}

int peek(struct stack r,int index)
{
    int x = -1;
    if (index>r.top | index<0)
    {
        printf("\nInvalid index\n");
        return x;
    }
    
    x = r.s[index];
    printf("\nElement at index %d is %d\n",index,x);
    return x;
}

void balanced_paranthesis(struct stack *s1,char *p)
{
    /*if(p==NULL)
    {
        printf("String is empty");
        return;
    }*/
    while(*p!='\0')
    {
        if(*p == '(')
        {
            push(s1,*p);
            p++;
        }
        else if(*p == ')')
        {
            pop(s1);
            p++;
        }
        else
            p++;
            continue;
        
    }
    if(s1->top == -1)
        printf("BP\n");
    else
        printf("No BP\n");
}


int main()
{
    struct stack my_stack;
    
    
    
    create(&my_stack);
    
    char str[50] = "((a+b)*(c-d))";
    
    balanced_paranthesis(&my_stack, str);

    /*
    isEmpty(my_stack);
    
    push(&my_stack,1);
    push(&my_stack,2);
    push(&my_stack,3);
    push(&my_stack,4);
    push(&my_stack,5);
    
    Display(my_stack);

    
    isFull(my_stack);
    
    pop(&my_stack);
    pop(&my_stack);
    
    StackTop(my_stack);
    
    peek(my_stack, 1);
    
     */
    
    return 0;
}
