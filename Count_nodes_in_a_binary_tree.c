int count(struct tree_node *p)
{
    int x,y;
    
    if(p!=NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}