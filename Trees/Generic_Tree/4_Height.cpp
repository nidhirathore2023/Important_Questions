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



// Height of  tree (edge-wise)
int Height(node *root)
{
    int hg=-1; // edge-wise
    for(auto child:root->childrens)
    {
        int ch_height=Height(child);
        hg=max(ch_height,hg);
    }

    hg=hg+1;
    return hg;
}

int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    cout<<"Height value of "<<Height(root);
    return 0;
}