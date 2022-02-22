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

int mx;// all in heap
int mi;
int h;
int si;

void mutisolver(node *root,int depth) // depth in stack (follow euler path)
{
    si++;
    mi=min(root->data,mi);
    mx=max(root->data,mx);
    h=max(h,depth);

    for(auto child:root->childrens)
    {
        mutisolver(child,depth+1);
    }
}


int main()
{
    node *root=NULL;
    insert(root);
    mx=INT_MIN;
    mi=INT_MAX;
    h=0;
    si=0;
    mutisolver(root,0);// root and depth 
    cout<<"Size "<<si<<"\n";
    cout<<"Height "<<h<<"\n";
    cout<<"Maximum value "<<mx<<"\n";
    cout<<"Minimum value "<<mi<<"\n";
    return 0;
}