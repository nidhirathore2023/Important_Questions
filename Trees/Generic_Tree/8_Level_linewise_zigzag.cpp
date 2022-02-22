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
    stack<node*>parent_st;// use ---> stack 
    stack<node*>child_st;
    parent_st.push(root);

    int le=1;// level

    while(!parent_st.empty())
    {
        node *temp=parent_st.top();
        parent_st.pop();
        cout<<temp->data<<" ";
        
        if(le%2!=0)// if odd level add values in increasing order
        {
           for(int i=0;i<temp->childrens.size();i++)
           {
               child_st.push(temp->childrens[i]);
           }

        }
        else// if odd add value in decreasing order
        {
            for(int i=temp->childrens.size()-1;i>=0;i--)
            {
                child_st.push(temp->childrens[i]);
            }
        }

        if(parent_st.empty())
        {
            cout<<"\n";
            
            parent_st=child_st;// copy value to parent in same order
            while(!child_st.empty())// empty child stack
            {
                child_st.pop();
            }
            le++;// increase level
        }
    }
}
      /*
      10 
      40 30 20
      50 60 70 80 90 120
      100 110
      */

int main()
{
    node *root=NULL;
    insert(root);
    //display(root);
    level(root);
    return 0;
}
