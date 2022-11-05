void insertItem(int k){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = k;
    newNode->lchild = newNode->rchild = NULL;

    if (root == NULL)
    {
        root = newNode;
        newNode->parent = NULL;
    }
    else
    {
        node *w = root;
        node *trail = NULL;
        while (w != NULL)
        {
            trail = w;
            if (k < w->key)
                w = w->lchild;
            else
                w = w->rchild;
        }
        newNode->parent = trail;
        if (k < trail->key)
            trail->lchild = newNode;
        else
            trail->rchild = newNode;
    }
}