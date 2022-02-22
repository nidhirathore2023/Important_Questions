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


int ceil_value;
int floor_value;

void ceil_floor(node *root,int key)
{
    if(root->data>key)
    {
        ceil_value=min(ceil_value,root->data);// smallest among larger
    }
    if(root->data<key)
    {
      floor_value=max(floor_value,root->data);// largest among smaller
    }
    for(auto child:root->childrens)
    {
        ceil_floor(child,key);
    }
}


int main()
{
    node *root=NULL;
    insert(root);
    floor_value=INT_MIN;//largest ammong smaller
    ceil_value=INT_MAX;// smallest among larger
    ceil_floor(root,90);
    cout<<"ceil "<<ceil_value<<"\n";
    cout<<"floor "<<floor_value<<"\n";
    return 0;
}