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
        //g[y].push_back(x);
    }
    stack<int>st;
    vector<bool>visited(v+1,false);
    visited[0]=true;
    st.push(0);
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
    return 0;
}