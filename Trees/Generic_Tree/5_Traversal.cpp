#include<iostream>
#include<vector>
#include<string>
#include<stack>
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


// Traversal of tree
/*
Node Pre 10
Edge Pre 10-20
Node Pre 20
Edge Pre 20-50
Node Pre 50
Node Post 50
Edge Post 20-50
Edge Pre 20-60
Node Pre 60
Node Post 60
Edge Post 20-60
Node Post 20
Edge Post 10-20
Edge Pre 10-30
Node Pre 30
Edge Pre 30-70
Node Pre 70
Node Post 70
Edge Post 30-70
Edge Pre 30-80
Node Pre 80
Edge Pre 80-110
Node Pre 110
Node Post 110
Edge Post 80-110
Edge Pre 80-100
Node Pre 100
Node Post 100
Edge Post 80-100
Node Post 80
Edge Post 30-80
Edge Pre 30-90
Node Pre 90
Node Post 90
Edge Post 30-90
Node Post 30
Edge Post 10-30
Edge Pre 10-40
Node Pre 40
Edge Pre 40-120
Node Pre 120
Node Post 120
Edge Post 40-120
Node Post 40
Edge Post 10-40
Node Post 10*/

void traverse(node *root)
{
    cout<<"Node Pre "<<root->data<<"\n";// at node (pre)
    for(auto child:root->childrens)
    {
        cout<<"Edge Pre "<<root->data<<"-"<<child->data<<"\n"; // at edge (pre)
        traverse(child);
        cout<<"Edge Post "<<root->data<<"-"<<child->data<<"\n";// at edge (post)
    }
    cout<<"Node Post "<<root->data<<"\n";// at node (post)
}

int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    traverse(root);
    return 0;
}