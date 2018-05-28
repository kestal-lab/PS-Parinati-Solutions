#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
node is defined as
*/
typedef struct node
{
   int data;
   node * left;
   node * right;
}node;


node* insert(node * root, int value) {
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
        root->left=insert(root->left,value);
    }
    else if(value> root->data)
    {
        root->right=insert(root->right,value);
    }

   return root;
}


int functionMin(node* root)
{
    if((root->left)->left!=NULL) return functionMin(root->left);

    if((root->left)->left==NULL)
    {
        int p=(root->left)->data;
        root->left=(root->left)->right;
        return p;
    }
}

node* deletenode(node* root,int value)
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
        root->right=deletenode(root->right,value);
        return root;
    }
    else
    {
        root->left=deletenode(root->left,value);
        return root;
    }
}

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

//function to print inorder traversal
void inorder(node* root)
{
    if(root==NULL) return ;


    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}


int main() {
    node* root=NULL;
    root=insert(root,95);
    root=insert(root,65);
    root=insert(root,105);
    root=insert(root,90);

    //function to print inorder traversal
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;

    node* temp=search(root,65);
    if(temp==NULL)
        cout<<"Not Found Sorry"<<endl;
    else cout<<"Entry found:" <<temp->data <<endl;

    root=deletenode(root,65);

    inorder(root);

}
