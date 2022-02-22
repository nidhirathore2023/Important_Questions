#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<climits>
using namespace std;
typedef struct node1{
    int data;
    vector<node1*>childrens;
    node1(int val)
    {
        data=val;
    }
}node;

vector<int>a ={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,120,-1,-1,-1};
// Insert 
void insert(node *&root)
{
    stack<node*>st;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==-1)
        {
            st.pop();
        }
        else
        {
            node *temp=new node(a[i]); 
            if(st.empty()) 
            {
                root=temp;
            }
            else
            {
                (st.top()->childrens).push_back(temp);
            }
            st.push(temp);
        }
    }
}

// Display 
void display(node *root)
{
    string s=to_string(root->data)+"->";
    for(auto child:root->childrens)
    {
        s+=to_string(child->data)+" ";
    }
    cout<<s<<"\n"; 

    for(auto child:root->childrens)
    {
        display(child);           
    }
}

// Remove Leaves
void remove_leaves(node *&root)
{ 
    // If only root is present delete it Or return NULL
    if(root->childrens.size()==0)
    {
      delete root;
    }
    /*
    NOTE-
    1- for(auto )--> loop will not work  --> concurrent modification error
    2- loop in reverse ---> otherwise vector element will shift --> on moving from back it does not affects logic of question
    3- Recursion --- >Pre- Order --- > problem with (80 node ) 
    */
    for(int i= root->childrens.size()-1;i>=0;i--)
    {
        node *child=root->childrens[i];// for root child at i
        if(child->childrens.size()==0) // if it does not have children
        {
            root->childrens.erase(root->childrens.begin()+i); // remove using erase function 
        }
    }
  // Recursion (call after work is done --> Preorder )
    for(auto child:root->childrens)
    {
        remove_leaves(child);
    }
}



int main()
{
    node *root=NULL;
    insert(root);
    display(root);
    remove_leaves(root);
    cout<<"\n";
    display(root);
    return 0;
}