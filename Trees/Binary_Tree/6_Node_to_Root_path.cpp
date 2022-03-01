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


// Node to Root path --> search (return bool ) ---> ans is in string ------>Travel and Solve*

bool node_to_root(node *root,string &path,int t)
{
   if(root==NULL)// if not get till null return false 
   {
       return false;
   }

   if(root->data==t)// if find then add to string return true
   {
       path+=to_string(root->data)+" ";
       return true;
   }
   bool l=node_to_root(root->left,path,t); // traverse left
   
   if(l==true) // if present in left family then add current node and return true
   {
    path+=to_string(root->data)+" ";
    return true;
   }

   bool r=node_to_root(root->right,path,t);// trevese right

   if(r==true) // if present in right family then add current node and return true
   {
    path+=to_string(root->data)+" ";
    return true;
   }

   return false;// if reached here --->  then not present in whole family  of current tree
}


int main()
{
    node *root=NULL;
    insert(root);
    string path="";
    node_to_root(root,path,70);
    cout<<"Node to Root path-"<<path;// note calls to reduce eular path
    return 0;
}