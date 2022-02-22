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

vector<int>a ={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
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


int floor_value;

// Ceil anf Floor
void ceil_floor(node *root,int key)
{
    if(root->data < key)
    {
        floor_value=max(floor_value,root->data);
    }
    for(auto child:root->childrens)
    {
        ceil_floor(child,key);
    }
}

// For kth largest 
/*
1th time- floor of INT_MAX;
2th time - floor of previous floor
..................k time


*/
int kthlargest(node *root ,int k)
{
    int factor=INT_MAX;
    for(int i=0;i<k;i++)
    {
      ceil_floor(root,factor);
      factor=floor_value;
      floor_value=INT_MIN;// floor --> int min
    }
    return factor;
}

int main()
{
    node *root=NULL;
    insert(root);
    floor_value=INT_MIN;
    cout<<kthlargest(root,4);
    return 0;
}