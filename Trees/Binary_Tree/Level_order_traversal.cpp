#include<iostream>
#include<queue>
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
// Level- Order Traversal --- > remove -> print -> add children
void level_order(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* a=q.front();// remove
        q.pop();
        cout<<a->data<<" ";// print 
        // add
        if(a->left!=NULL)// if left present -->push to queue
        {
            q.push(a->left);
        }
        if(a->right!=NULL)// if right present --> push to queue
        {
            q.push(a->right);
        }
    }
    return ;
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
    root->left->left->right=new node(8);
    root->left->right->right=new node(9);
    level_order(root);
    return 0;
}