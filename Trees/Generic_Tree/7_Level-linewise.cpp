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



// Level Order  (Line-Wise -> Two queue)  ---> Remove - Print - Fill
void level(node *root)
{
    queue<node*>parent_q;// store parent of current level
    queue<node*>child_q;// store children of current lavel
    parent_q.push(root);
    while( !parent_q.empty())
    {
        node *temp=parent_q.front();
        parent_q.pop();
        cout<<temp->data<<" ";
        for(auto child :temp->childrens)
        {
            child_q.push(child);
        }

        if(parent_q.empty())
        {
            cout<<"\n";
            while(!child_q.empty())
            {
                node *t=child_q.front();
                child_q.pop();
                parent_q.push(t);
            }
        }
    }
}

/*
10 
20 30 40
50 60 70 80 90 120
110 100
*/

int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    level(root);
    return 0;
}