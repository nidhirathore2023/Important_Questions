#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
typedef struct node1{
    int data;
    vector<node1*>childrens;
    node1(int val)
    {
        data=val;
    }
}node;

vector<int>a ={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,100,-1,-1,-1};
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



// Size  of tree

int size_tree(node *root)
{                                //--> no base condition -> call if child present 
    int t=0;
    for(auto child:root->childrens)// childrens will give there family number 
    {
        t+=size_tree(child);
    }
    return t+1; // add 1 -> parent with rest of family 
}

int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    cout<<"Size of "<<size_tree(root);
    return 0;
}