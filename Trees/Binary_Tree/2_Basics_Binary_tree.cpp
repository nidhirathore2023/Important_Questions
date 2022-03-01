#include<iostream>
using namespace std;
typedef struct node1{
    int data;
    node1 * left;
    node1 * right;

    node1(int val)
    {
      data=val;
      left=NULL;
      right=NULL;
    }
}node;
// Inorder Traversal
void Inorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
// Preoder Traversal

void Preorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder Traversal

void Postorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root=NULL;
    root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    Inorder(root);
    cout<<"\n";
    Postorder(root);
    cout<<"\n";
    Preorder(root);
    return 0;
}