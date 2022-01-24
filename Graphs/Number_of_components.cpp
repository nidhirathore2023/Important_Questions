// Most of the graphs are given connected (having one component) but if we have more than one components in graph
// then use this dfs algorithm 
#include<iostream>
#include<vector>
#include<stack>
using  namespace std;// T.C = O(V+E) 
                    //S.C =O(V) (stack)
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>g[v+1];// array of vector
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int c=0;
    vector<bool>visited(v+1,false);
    for(int i=1;i<=v;i++) // -----------> checking for all component 
    {
    if(!visited[i])
    {
        c++;
      stack<int>st;
    visited[i]=true;
    st.push(i);
    while(!st.empty())
    {
      int cur=st.top();
      st.pop();
      cout<<cur<<" ";
      for(auto x:g[cur])
      {
          if(visited[x]!=true)
          {
              visited[x]=true;
              st.push(x);
          }
      }
    }
    }
    }
    cout<<"\n";
    cout<<"Number of components "<<c;
    return 0;
}
