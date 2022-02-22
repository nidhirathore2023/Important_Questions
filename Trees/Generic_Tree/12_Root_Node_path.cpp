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



// Node to root Path
bool node_root_Path(node *root,vector<int>&ans,int key)
{
    if(root->data==key)
    {
        ans.push_back(root->data);
        return true;
    }

    for(auto child:root->childrens)
    {
        bool present=node_root_Path(child,ans,key);
        if(present)
        {
            ans.push_back(root->data);
            return true;
        }
    }
     
    return false;
}
int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    vector<int>ans;
    cout<<node_root_Path(root,ans,110)<<"\n";
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}