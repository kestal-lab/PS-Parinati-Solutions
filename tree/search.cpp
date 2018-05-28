node* search(node* root,int value)
{
    if(root==NULL) return NULL;

    node* left=NULL;
    if(value==root->data) return root;
    else if(value<root->data) left= search(root->left,value);
    else left=search(root->right,value);

    if(left!=NULL) return left;
    else return NULL;
}