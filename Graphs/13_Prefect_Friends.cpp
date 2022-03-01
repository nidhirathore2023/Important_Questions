#include<iostream>
#include<vector>
#include<stack>
using namespace std;
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
    vector<vector<int>>Components;// Store components of graphs 
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            stack<int>st;
            st.push(i);
            visited[i]=true;
            vector<int>mini_compoenent;

            while(!st.empty())
            {
                int temp=st.top();
                st.pop();
                mini_compoenent.push_back(temp);
                for(auto x:graph[temp])
                {
                    if(visited[x]==false)
                    {
                        st.push(x);
                        visited[x]=true;
                    }
                }
            }

            Components.push_back(mini_compoenent);

        }
    }
    int pairs=0; // get number of unique pairs from one compoenent to another 
    for(int i=0;i<Components.size();i++)
    {
        for(int j=i+1;j<Components.size();j++)
        {
            int count=Components[i].size()*Components[j].size();
            pairs+=count;
        }
    }
    cout<<pairs<<" \n";
    return 0;
}