#include<iostream>
#include<climits>
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

// Size of trees ---- > Total number of nodes in tree
int size(node *root)// total number of nodes
{
  if(root==NULL)
  {
      return 0;
  }
  int ls=size(root->left);
  int rs=size(root->right);
  int ts=ls+rs+1;// add itself
  return ts;
}

// Sum ---> all nodes
int sum(node * root)
{
  if(root==NULL)
  {
    return 0;
  }
  int l_sum=sum(root->left);
  int r_sum=sum(root->right);
  int to_sum=l_sum+r_sum+root->data;// add it's data
  return to_sum;
}

//Maximum node 
int Maximum(node *root)
{
  if(root==NULL)
  {
    return INT_MIN;
  }
  int l_max=Maximum(root->left);
  int r_max=Maximum(root->right);
  int Over_all_max=max(max(l_max,r_max),root->data);// maximum of left,right and itself
  return Over_all_max;
}

//Height ---> edges -----> height of deepest Node
int Height(node *root)
{
  if(root==NULL)
  {
    return -1;// edges && for nodes  return 0;
  }

  int l_he=Height(root->left);
  int r_he=Height(root->right);
  int he=max(l_he,r_he)+1;// maximum of left height and right height + 1
  return he;
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
    cout<<"Size "<<size(root)<<"\n";
    cout<<"Sum "<<sum(root)<<"\n";
    cout<<"Maximum "<<Maximum(root)<<"\n";
    cout<<"Height (edge-wise) "<<Height(root)<<"\n";
    return 0;
}