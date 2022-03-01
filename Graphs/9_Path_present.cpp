#include<iostream>
#include<vector>
using namespace std;
bool IsPath(int src,int des,vector<int>graph[],vector<bool>& visited)
{
    if(des==src)
    {
        return true;
    }
    visited[src]=true;
    for(auto x:graph[src])
    {
        if(visited[x]==false){
          bool p=IsPath(x,des,graph,visited);
          if(p==true)
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
    vector<int>graph[v];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int src,des;
    cin>>src>>des;
    vector<bool>visited(v,false);
    cout<<IsPath(src,des,graph,visited);// using DFS ---> Recursion Stack
    return 0;
}