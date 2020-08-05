struct tree_node * ISearch(struct tree_node *t, int key)
{
    // If root node does not exist, return NULL
    if(t==NULL)
        return NULL;
    
    while(t!=NULL)
    {
    if(t->data == key)
        return t;
    else if(t->data >key)
    {
        t = t->lchild;
    }
    else if(t->data < key)
    {
        t=t->rchild;
    }
    }
    
    return NULL;
}

struct tree_node * RSearch(struct tree_node *t, int key)
{
    if(t == NULL)
        return NULL;
    
    if(key == t->data)
        return t;
    else if(key <t->data)
        return RSearch(t->lchild, key);
    else if(key > t->data)
        return RSearch(t->rchild, key);
    
    return NULL;
}