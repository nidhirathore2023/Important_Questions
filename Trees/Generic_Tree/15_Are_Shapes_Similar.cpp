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
vector<int>a1 ={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,120,-1,-1,-1};
void insert1(node *&root)
{
    stack<node*>st;
    for(int i=0;i<a1.size();i++)
    {
        if(a1[i]==-1)
        {
            st.pop();
        }
        else
        {
            node *temp=new node(a1[i]); 
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



// Are two Trees Similar in shape ---> (only if no. of childrens are equal)
bool similar(node *root1,node *root2)
{
    if(root1->childrens.size()!=root2->childrens.size())// if size of childrens is not equal cannot be similar
    {
        return false;
    }
    for(int i=0;i<root1->childrens.size();i++)
    {
        node *child1=root1->childrens[i];
        node *child2=root2->childrens[i];
        if(!similar(child1,child2)) // if any child is not similar --> not similar 
        {
            return false;
        }
    }
    return true; // will similar 
}
int main()
{
    node *root1=NULL;
    insert(root1);
    node *root2=NULL;
    insert1(root2);
    //display(root);
    cout<<similar(root1,root2);
    return 0;
}