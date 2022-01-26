#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// TC = O(V+E) ,SC = O(V) ( for queue)
vector<bool>vis;
bool cycle(int i,vector<int>g[])
{
    queue<pair<int,int>>q;//--->queue of pairs ---> node and it's parent 
    q.push({i,-1});// first node does not have parent ---> push({i ,-1})
    vis[i]=true;
    while(!q.empty())
    {
        int node=q.front().first;//get node
        int prev=q.front().second;// get previous or parent node
        q.pop();
        for(auto x:g[node])
        {
            if(!vis[x])
            {
                vis[x]=true;
                q.push({x,node});//push current node and it's parent 
            }
            else if(prev!=x)//if node is visited and have different parent then there is cycle in graph
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>g[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool flag=false;
    vis=vector<bool>(v+1,false);
    for(int i=1;i<=v;i++)// Graph with different components 
    {
        if(!vis[i])
        {
            if(cycle(i,g))//check cycle
            {
                flag=true;
                break;
            }
            
        }
    }
    if(flag)
    {
        cout<<"Cycle present ";
    }
    else
    {
        cout<<"No Cycle ";
    }
    return 0;
}