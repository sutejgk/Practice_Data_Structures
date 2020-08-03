//
//  main.c
//  Tree
//
//  Created by Sutej Kulkarni on 03/08/20.
//  Copyright © 2020 Sutej Kulkarni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


struct tree_node *root = NULL;

void create()
{
    //Create root node
    // x is used throughout to hold node values
    int x;
    printf("Enter root node value:\n");
    scanf("%d",&x);
    
    root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    
    //Create Queue
    
    struct qu q;
    
    create_queue(&q,100);
    enqueue(&q, root);
    
    // So now queue has a single address which is the root node address
    // Next we will start adding the other nodes
    
    //*p : pointer to hold the dequeued addresses
    //*t : pointer to create remaining tree nodes
    
    struct tree_node *p = NULL,*t = NULL;
    
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter %d's left child value:\n",p->data);
        scanf("%d",&x);
        
        if(x != -1)
        {
            t = (struct tree_node*)malloc(sizeof(struct tree_node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        
        printf("Enter %d's right child value:\n",p->data);
        scanf("%d",&x);
        
        if(x != -1)
        {
            t = (struct tree_node*)malloc(sizeof(struct tree_node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
        
    }
    
    
}

void preo(struct tree_node *s)
{
    if(s)
    {
    printf("%d ",s->data);
    preo(s->lchild);
    preo(s->rchild);
    }
}

void ino(struct tree_node *s1)
{
    if(s1)
    {
    ino(s1->lchild);
    printf("%d ",s1->data);
    ino(s1->rchild);
    }
}

void posto(struct tree_node *s2)
{
    if(s2)
    {
    posto(s2->lchild);
    posto(s2->rchild);
    printf("%d ",s2->data);

    }
}

int main()
{
    create();
    
    printf("In order:\n");
    ino(root);
    printf("\nPre order:\n");
    preo(root);
    printf("\nPost order:\n");
    posto(root);
    return 0;
}
