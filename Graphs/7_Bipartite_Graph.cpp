#include<iostream>
#include<vector>
using namespace std;//TC = O(V+E ), SC =O(V) -->visited,and color array
vector<bool>vis;
vector<int>col;
bool flag;
void  color(int u,int curr,vector<int>g[])
{
    if(col[u]!=-1 && col[u]!=curr)//if not colored and not the color we want to assign it
    {
        flag=false;
        return;
    }
    col[u]=curr;
    if(vis[u])
    {
        return ;
    }
    vis[u]=true;
    for(auto x:g[u])
    {
        color(x,curr xor 1,g);// 0 xor 1= 1 && 1 xor 1 =0
    }
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
    vis=vector<bool>(v+1,false);
    col=vector<int>(v+1,-1);
    flag=true;
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            color(i,0,g);//color function 
        }
    }
    if(flag)
    {
      cout<<"Bipartite ";
    }
    else
    {
        cout<<"Not Bipartite ";
    }
    return 0;
}