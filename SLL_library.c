//
//  practice_array.c
//  Recursive_function
//
//  Created by Sutej Kulkarni on 13/07/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"

struct sll_node
{
    int data;
    struct sll_node *next;
};

struct sll_node *first = NULL;
struct sll_node *second = NULL;

void create_my_sll(int a[],int n)
{
    struct sll_node *t = NULL,*last = NULL;
    int i=0;
    
    first = (struct sll_node*)malloc(sizeof(struct sll_node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    
    for(i=1;i<n;i++)
    {
        t = (struct sll_node*)malloc(sizeof(struct sll_node*));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void create_my_sll2(int a[],int n)
{
    struct sll_node *t = NULL,*last = NULL;
    int i=0;
    
    second = (struct sll_node*)malloc(sizeof(struct sll_node));
    second->data = a[0];
    second->next = NULL;
    last = second;
    
    for(i=1;i<n;i++)
    {
        t = (struct sll_node*)malloc(sizeof(struct sll_node*));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display_my_sll(struct sll_node *b)
{
    while(b!=NULL)
    {
        printf("%d ",b->data);
        b= b->next;
    }
}


//Analysis of this function is O(n) since it is visiting all the nodes once
int sum_of_elements_of_ll(struct sll_node *q)
{
    int sum = 0;
    while(q!=NULL)
    {
        sum = sum + q->data;
        q = q->next;
    }
    return sum;
}

int count(struct sll_node *r)
{
    int count = 0;
    while(r!=NULL)
    {
        count = count+1;
        r = r->next;
    }
    return count;
}

//Recursive function for sum and count need to do


int max_element_sll(struct sll_node *s1)
{
    int max = -99999999;
    
    if(s1==NULL)
    {
        printf("No elements in LL");
        return 0;
    }
        
    
    while(s1!=NULL)
    {
        if(s1->data > max)
        {
            max = s1->data;
        }
        s1 = s1->next;
    }
    return max;
}

void insert_in_my_sll(struct sll_node *a1,int data1, int loc)
{
    if(loc<0 || loc > count(first)+1)
    {
        printf("Invalid position\n");
        return;
    }
    if(loc == 0)
    {
        struct sll_node *s1=NULL;
        s1 = (struct sll_node*)malloc(sizeof(struct sll_node));
        s1->data = data1;
        s1->next = first;
        first = s1;
    }
    else
    {
        struct sll_node *s2=NULL, *p=NULL;
        int i=0;
        s2 = (struct sll_node*)malloc(sizeof(struct sll_node));
        s2->data = data1;
        s2->next = NULL;
        
        p = first;
        
        for(i=1;i<=loc-2;i++)
        {
            p = p->next;
        }
        s2->next = p->next;
        p->next = s2;
    }
}

void Insert_last(struct sll_node *r,int data2)
{
    if(r==NULL)
    {
        //printf("No nodes in LL\n");
        struct sll_node *v = NULL;
        v = (struct sll_node*)malloc(sizeof(struct sll_node));
        v->data = data2;
        v->next = NULL;
        first = v;
        return;
    }
    
    struct sll_node *v1 = NULL, *p=NULL;
    v1 = (struct sll_node*)malloc(sizeof(struct sll_node));
    v1->data = data2;
    v1->next = NULL;
    
    p=r;
    
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next = v1;
}

void Insert_in_sorted_list(struct sll_node *s1,int data10)
{
    struct sll_node *s5=NULL;
    s5 = (struct sll_node*)malloc(sizeof(struct sll_node));
    if (s1==NULL)
    {
        s5->data = data10;
        s5->next = NULL;
        first = s5;
        return;
    }
    
    s5->data = data10;
    s5->next = NULL;
    
    struct sll_node *p=NULL, *q=NULL;
    p=s1;
    q = p->next;
    while(q!=NULL)
    {
      if(q->data >= data10 & p->data <= data10)
      {
          p->next = s5;
          s5->next = q;
          return;
      }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    
}

int delete_a_node_in_SLL(struct sll_node *q1,int pos)
{
    //Check if user has given a valid position
    int x=-1;
    if(pos < 1 || pos > count(q1))
    {
        
        printf("Invalid position!\n");
        return x;
    }
    
    if(q1==NULL)
    {
        printf("No nodes in LL\n");
        return x;
    }
    
    //Deleting the first node
    if(pos==1)
    {
        struct sll_node *p1=NULL;
        p1 = first;
        first = first->next;
        x = p1->data;
        free(p1);
        return x;
    }
    
    //Deleting any node other than first node
    
    else
    {
        struct sll_node *p=NULL,*q=NULL;
        int i=1;
        p = first;
        q = p->next;
        
        for(i=1;i<=pos-2;i++)
        {
            p = p->next;
            q = q->next;
        }
        
        p->next = q->next;
        x = q->data;
        free(q);
        return x;
    }
}

void check_if_ll_is_sorted(struct sll_node *p2)
{
    struct sll_node *p=NULL,*q=NULL;
    
    if(p2==NULL)
    {
        printf("\nLL is empty\n");
        return;
    }
    
    if(count(p2)==1)
    {
        printf("\nLinked list contains just 1 value\n");
        return;
    }
    
    p=first;
    q=p->next;
    
    while(q!=NULL)
    {
        if(p->data < q->data)
        {
            p = p->next;
            if(q->next==NULL)
            {
                printf("\nLL is sorted, Badhai Ho!!\n");
                return;
            }
            q=q->next;
            continue;
        }
        else
        {
            printf("\nLL is not sorted!!\n");
            return;
        }
    }
}

void remove_duplicates(struct sll_node *s11)
{
    struct sll_node *p=NULL,*q=NULL;
    if(s11==NULL)
    {
        printf("\nLL is empty\n");
        return;
    }
    
    if(count(s11)==1)
    {
        printf("\nLinked list contains just 1 value\n");
        return;
    }
    
    p =first;
    q = p->next;
    
    while(q->next!=NULL)
    {
    if(p->data != q->data)
    {
        p = p->next;
        q = q->next;
    }
    else
    {
        p->next = q->next;
        free(q);
        q=p->next;
    }
    }
}

void concatenate_two_LLs(struct sll_node *l1,struct sll_node *l2)
{
    struct sll_node *pl=NULL;
    
    pl = l1;
    while(pl->next!=NULL)
    {
        pl = pl->next;
    }
    pl->next = l2;
    free(l2);
}

void reverse_my_ll(struct sll_node *p1)
{
    int array[100] = {};
    int i=0;
    p1 =first;
    
    while(p1!=NULL)
    {
        array[i] = p1->data;
        p1 = p1->next;
        i++;
    }

    p1 = first;
    i--;
    while(p1!=NULL)
    {
        p1->data = array[i];
        p1 = p1->next;
        i--;
    }
}

int main()
{
    int A[7] = {1,3,3,3,5,5,8};
    create_my_sll(A,7);
    //int B[5] = {100,101,699};
    //create_my_sll2(B,3);
    printf("\n");
    
    //concatenate_two_LLs(first, second);
    display_my_sll(first);
    //printf("\n");
    
    reverse_my_ll(first);
    printf("\n");

    display_my_sll(first);

    
    
    return 0;
}
