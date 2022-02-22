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

vector<int>a ={10,20,-50,-1,-60,-1,-1,30,70,-1,80,110,-1,-120,-1,-1,-90,-1,-1,40,100,-1,-1,-1};
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

node *ans;
int mx;
int max_sum_subtree(node *root)
{
  
  int s=0;
  for(auto child:root->childrens)
  {
      int t=max_sum_subtree(child);
      s+=t;
  }
  s=s+root->data;
  if(s>mx)
  {
      mx=s;
      ans=root;
  }
  return s;
}



int main()
{
    node *root=NULL;
    insert(root);
    mx=INT_MIN;
    max_sum_subtree(root);
    cout<<ans->data<<" ";
    cout<<mx<<" ";
    return 0;
}