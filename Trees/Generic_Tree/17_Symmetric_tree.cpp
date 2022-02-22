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

vector<int>a ={10,20,30,-1,-1};
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

// Mirror Image
bool mirror(node *root1,node *root2)
{
    if(root1->childrens.size()!=root2->childrens.size())
    {
        return false;
    }

    for(int i=0;i<root1->childrens.size();i++)
    {
        int j=root1->childrens.size()-i-1;
        node *child1=root1->childrens[i];
        node *child2=root2->childrens[j];
        
        if(!mirror(child1,child2))
        {
            return false;
        }
    }
    return true;
}


// Symmetric tree ---->( Mirror image of itself)----------> Another question number of levels---> upto which binary tree is symmetric
bool symmetric(node *root)
{
    return mirror(root,root);
}


int main()
{
    node *root=NULL;
    insert(root);
    cout<<symmetric(root);
    return 0;
}