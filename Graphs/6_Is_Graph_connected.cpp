#include<iostream>
#include<vector>
#include<stack>
using namespace std;  
//If number of compenents = 1 --->Connected Graph 
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>graph[v];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool>visited(v,false);
    int number_of_component=0;
    for(int i=0;i<v;i++)
    {
        stack<int>st;
        if(visited[i]==false)
        {
          visited[i]=true;
          st.push(i);
          number_of_component++;
        }
        while(!st.empty())
        {
            int temp=st.top();
            st.pop();
            for(auto x:graph[temp])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    st.push(x);
                }
            }
        }
        
    }
    if(number_of_component==1)
    {
        cout<<"YES  ";
    }
    else
    {
        cout<<"NO ";
    }
    return 0;
}
        
