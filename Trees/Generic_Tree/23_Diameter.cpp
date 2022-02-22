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




//Diameter  
// Travel and Change 
int diameter;
int Diameter(node *root)
{
    int dch=-1;
    int sdc=-1;
    for(auto child:root->childrens)
    {
        int ch=Diameter(child);
        if(ch>dch)
        {
            sdc=dch;
            dch=ch;
        }
        else if(ch>sdc)
        {
            sdc=ch;
        }
    }
    int t=dch+sdc+2;
    diameter=max(t,diameter);

    dch+=1;
    return dch;
}

int main()
{
    node *root=NULL;
    insert(root);
    diameter=INT_MIN;
    Diameter(root);
    cout<<diameter;
    return 0;
}