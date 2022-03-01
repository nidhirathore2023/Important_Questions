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


// K-level down (print all element at certain level) -> Root = 0 level
/*
1-method -linewise level order trversal
2-method -simple function
*/

void k_level_down(node* root,int k)
{
    if(root==NULL || k<0)// not need to go down further 
    {
        return ;
    }
    if(k==0) // if at required level --> print 
    {
        cout<<root->data<<" ";
    }

    k_level_down(root->left,k-1);// left call
    k_level_down(root->right,k-1);// right call
}

int main()
{
    node *root=NULL;
    insert(root);
    k_level_down(root,2);
    return 0;
}