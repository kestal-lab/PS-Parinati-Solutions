/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value) {
    if(root==NULL)
    {
    	node* a=new node();
    	a->data=value;
    	a->left=NULL;
    	a->right=NULL;
        //you were missing this root=a you idiot, har bar same mistake repeat
        root=a;
    }
    else if(value< root->data)
    {
        insert(root->left,value);
    }
    else if(value> root->data)
    {
        insert(root->right,value);
    }
    
   return root;
}
