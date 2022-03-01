#include<iostream>
#include<vector>
using namespace std;
void All_paths(int src,int des,vector<int>graph[],vector<bool>&visited,string psf)
{
  if(src==des)
  {
      cout<<psf<<"\n";
      return ;
  }
  visited[src]=true; // preorder --> visited 
  for(auto x:graph[src])
  {
    if(visited[x]==false)
    {
        All_paths(x,des,graph,visited,psf+" "+to_string(x));// add current vertex to path so far
    }
  }
  visited[src]=false;// Postorder --> unvisited 
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

    vector<bool>visited(v,false);
    int src,des;
    cin>>src>>des;
    All_paths(src,des,graph,visited,to_string(src)+"");// using Backtracking 
    return 0;
}


