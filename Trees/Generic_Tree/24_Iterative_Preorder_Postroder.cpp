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

//Iterative Preorder and Postorder
void Iterative(node *&root)
{
    stack<pair<node*,int>>st;
    st.push({root,-1});
    string pre;
    string post;
    while(!st.empty())
    {
        if(st.top().second==-1)// if top-> state =-1 preorder 
        {
            pre+=to_string(st.top().first->data)+" ";
            st.top().second++;
        }
        else if(st.top().second == st.top().first->childrens.size())// if top ->state == size of childrens =post order
        {
            post+=to_string(st.top().first->data)+" ";
            st.pop();
        }
        else 
        {
            st.top().second++;// note  this point (i-1) 
            st.push({st.top().first->childrens[st.top().second-1],-1});// very very important point
        }
        
    }
   
    cout<<"Preorder "<<pre<<"\n"<<"Postorder "<<post;
}


int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    Iterative(root);
    return 0;
}