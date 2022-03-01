#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef struct node1{
    int data;
    node1* left;
    node1*right;

    node1(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

}node;
int a[]={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};

// Create Binary tree from array
void insert(node*&root)
{
    stack<pair<node*,int>>st;
    node *temp=new node(a[0]);
    root=temp;
    st.push({root,1}); // create node root and push
    int i=0;
    while(!st.empty())
    {
        if(st.top().second==1) // left node 
        {
            i++;
            st.top().second++; // increase state ---> because after top will change
           if(a[i]!=-1)// if exist --> create node ----> set left of stack top ---> push node in stack
           {
             node *temp=(node*)malloc(sizeof(node));
             temp->data=a[i];
             temp->left=NULL;
             temp->right=NULL;
             (st.top().first)->left=temp;
             st.push({temp,1});
           }
           else
           {
             (st.top().first)->left=NULL; // else right is null
           }

        }
        else if(st.top().second==2)//right node 
        {
            i++;
           st.top().second++;// increase state 
           if(a[i]!=-1) //if exist --> create node ----> set right of stack top ---> push node in stack
           {
             node *temp=(node*)malloc(sizeof(node));
             temp->data=a[i];
             temp->left=NULL;
             temp->right=NULL;
             (st.top().first)->right=temp;
             st.push({temp,1});
           }
           else
           {
               (st.top().first)->right=NULL;// else right is null
           }
        }
        else if(st.top().second==3) // if state is 3 POP
        {

            st.pop();
        }
    }
}

//Iterative Traversal
void Iterative(node *root,string &pre,string &post,string &in)
{
    stack<pair<node*,int>>st;// stack pair ---> node ,state (1-preoder ,2-inorder,3-postorder)
    st.push({root,1});
    while(!st.empty())
    {
        if(st.top().second==1) // state 1 -preorder increase state and push left child
        {
            pre+=to_string(st.top().first->data)+" ";
            st.top().second++;
            if(st.top().first->left!=NULL)
            {
            st.push({st.top().first->left,1});
            }
        }
        else if(st.top().second==2)//state 2 -inorder incresse state and push right child
        {
            in+=to_string(st.top().first->data)+" ";
            st.top().second++;
            if(st.top().first->right!=NULL)
            {
            st.push({st.top().first->right,1});
           }
        }
        else if(st.top().second==3)// state 3 -postorder pop
        {
            post+=to_string(st.top().first->data)+" ";
            st.pop();
        }
    }
}
/*
Preorder 50 25 12 37 30 75 62 70 87 
Postorder 12 30 37 25 70 62 87 75 50
Inorder 12 25 30 37 50 62 70 75 87
*/


int main()
{
    node *root=NULL;
    insert(root);
    //show(root);
    string pre,post,in;
    Iterative(root,pre,post,in);
    cout<<"Preorder "<<pre<<"\n";
    cout<<"Postorder "<<post<<"\n";
    cout<<"Inorder "<<in<<"\n";
    return 0;
}