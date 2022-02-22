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
void node_root_Path(node *root,int key,vector<int>&ans)
{
    if(root->data==key)
    {
        ans.push_back(root->data);
        return ;
    }
    for(auto child:root->childrens)
    {
        node_root_Path(child,key,ans);
        if(ans.size()>0)
        {
            ans.push_back(root->data);
            return;
        }
    }
}




// Distance Between Two Nodes
int distance(node *root,int n1,int n2)
{
    vector<int>ans1;
    vector<int>ans2;
    node_root_Path(root,n1,ans1);
    node_root_Path(root,n2,ans2);
    int i=ans1.size()-1;
    int j=ans2.size()-1;
    while(i>=0 && j>=0 && ans1[i]==ans2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return (i+j);// distance between two nodes
}
  
int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    cout<<distance(root,10,50);
    return 0;
}