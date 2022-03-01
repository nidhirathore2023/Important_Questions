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
 //Display function 
void show(node* root)
{
    if(root==NULL) //---> not required in n-Array tree call are on the bases of children size
    {
        return;
    }
    string s="";
    if(root->left!=NULL)
    {
        int p=root->left->data;
        s+=to_string(p);
    }
    else
    {
        s+='.';
    }
    s+="<-"+to_string(root->data)+"->";
    if(root->right!=NULL)
    {
        int p=root->right->data;
        s+=to_string(p);
    }
    else
    {
        s+='.';
    }
    cout<<s;
    cout<<"\n";
    show(root->left);
    show(root->right);
}
/*
Preorder --> special travresal 
25<-50->75
12<-25->37
.<-12->.
30<-37->.
.<-30->.
62<-75->87
.<-62->70
.<-70->.
.<-87->.
*/


int main()
{
    node *root=NULL;
    insert(root);
    show(root);
    return 0;
}