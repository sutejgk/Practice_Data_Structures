void preorder_iterative(struct tree_node *t)
{
    struct stack st;
    
    create(&st);
    
    while(t!=NULL || !isEmpty_st(st))
    {
        if(t!=NULL)
        {
            // 1. Print the data
            printf("%d ",t->data);
            // 2. Push its address onto the stack
            push(&st, t);
            // 3.Move 't' to its left child
            t = t->lchild;
        }
        else
        {
            // 1.Pop the previous address from the stack
            t = pop(&st);
            // 2. Go to the right child
            t = t->rchild;
        }
    }
}

void inorder_iterative(struct tree_node *t)
{
    struct stack st;
    
    create(&st);
    
    while(t!=NULL || !isEmpty_st(st))
    {
        if(t!=NULL)
        {
            // 1. Push its address onto the stack
            push(&st, t);
            // 2. Move 't' to its left child
            t = t->lchild;
        }
        else
        {
            // 1.Pop the previous address from the stack
            t = pop(&st);
            // 2. Print the data
            printf("%d ",t->data);
            // 3. Go to the right child
            t = t->rchild;
        }
    }
}