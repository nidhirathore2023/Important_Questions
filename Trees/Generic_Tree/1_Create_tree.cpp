#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
typedef struct node1{
    int data;                   // data  of node
    vector<node1*>childrens;    //all childrens are stored in vector of childrens

// Constructor
    node1(int val)// use new mathod ---> allocate memeory 
    {
     data=val;
    }
}node;

// Given array --- >make Generic tree
vector<int>a ={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,100,-1,-1,-1};

// Insert function
void insert(node *&root)
{
    stack<node*>st;//-----------> use stack 
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==-1)// if current element is -1 no child ---> pop
        {
            st.pop();
        }
        else// else create node 
        {
            node *temp=new node(a[i]); // use new method 
            if(st.empty()) // if stack is empty -> first element is root node 
            {
                root=temp;
            }
            else
            {
                (st.top()->childrens).push_back(temp);// else add children of stack top
            }
            st.push(temp);// push node in stack
        }
    }
}

//Display Function 

void display(node *root)
{
    string s=to_string(root->data)+"->";
    for(auto child:root->childrens)// for childrens of root node 
    {
        s+=to_string(child->data)+" ";
    }
    cout<<s<<"\n"; //---> print string 

    for(auto child:root->childrens)// Faith --> children will take Care of there on family 
    {
        display(child);           // Recursion
    }
}

/*
10->20 30 40 
20->50 60
50->
60->
30->70 80 90
70->
80->110 100
110->
100->
90->
40->100
100->
*/
int main()
{
    node *root=NULL;// Create Root node
    insert(root);//insert  values 
    display(root);// display values
    return 0;
}