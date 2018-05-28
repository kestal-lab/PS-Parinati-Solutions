int functionMin(Node* root)
{
    if((root->left)->left!=NULL) return functionMin(root->left);

    if((root->left)->left==NULL) 
    {
        int p=(root->left)->data;
        root->left=(root->left)->right;
        return p;
    }
}

Node* deleteNode(Node* root,int value)
{
    if(root==NULL) return NULL;

    if(root->data== value)
    {
        if(root->left==NULL)  return root->right;
        else if(root->right==NULL) return root->left;
        else 
        {
            if((root->right)->left==NULL) 
            {
                root->data=(root->right)->data;
                root->right=(root->right)->right;
            }
            else root->data=functionMin(root->right);
        }
    }
    else if(value>root->data)
    {
        root->right=deleteNode(root->right,value);
        return root;
    }
    else
    {
        root->left=deleteNode(root->left,value);
        return root;
    }
}

