#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<bool>visited;
/*
//     Get Component Code

  Topological Sort - > if one thing depend on other thing then how this things
  to be done so that independent things are done before (toplogical sort in reverse order)
*/
void topoogical_sort(vector<int>graph[],stack<int>&st,int i)
{
    visited[i]=true;
    for(auto x:graph[i])// For unvisited Neighbour
    {
        if(!visited[x])
        {
            topoogical_sort(graph,st,x);
        }
    }

    st.push(i);// push ---> in POST_ORDER

    /*
    NOTE- 
    1- Not printing every vertices instantly---> problem in other components
    2- Not pre-order --> not give desired Output */
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>graph[v]; // 0- Indexing 
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }

    // Print Graph 
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(auto x:graph[i])
        {
            cout<<"->"<<x;
        }
        cout<<"\n";
    }
    cout<<"\n";


    visited=vector<bool>(v,false); //  0 -Indexing 
    stack<int>st;// --->Store Final Result
    for(int i=0;i<v;i++)
    {
        if(!visited[i])// if not visited 
        {
            topoogical_sort(graph,st,i); //------> call topological sort 
        }
    }
   //Print Stack 
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}


