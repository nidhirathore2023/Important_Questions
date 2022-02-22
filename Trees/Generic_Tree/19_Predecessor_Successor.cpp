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

int pr;
int su;
int state;
void predecessor_successor(node *root,int key)
{
    if(state==0)
    {
       if(root->data==key)
       {
           state=1;
       }
       else
       {
           pr=root->data;
       }
    }
    else if(state==1)
    {
      state=2;
      su=root->data;
    }

    for(auto child:root->childrens)
    {
        predecessor_successor(child,key);
    }
}



int main()
{
    node *root=NULL;
    insert(root);
    state=0;
    //display(root);
    predecessor_successor(root,90);
    cout<<"Predecessor "<<pr<<"\n";
    cout<<"Successor "<<su<<"\n";
    return 0;
}