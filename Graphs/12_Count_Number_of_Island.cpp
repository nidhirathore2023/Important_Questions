#include<iostream>
#include<vector>
using namespace std;

// Get Connected Components Extension
void drawTreeforComponent(vector<vector<int>>graph,int i,int j,vector<vector<bool>> &visited)
{
    if(i<0 ||  j<0 || i>=graph.size() ||  j>=graph.size() || graph[i][j]==1 || visited[i][j]==true)  // check --> Outside boundary , visited , edge present 
    {
        return ;
    }
    visited[i][j]=true;
    drawTreeforComponent(graph,i-1,j,visited); // North
    drawTreeforComponent(graph,i+1,j,visited); // South 
    drawTreeforComponent(graph,i,j-1,visited); // West
    drawTreeforComponent(graph,i,j+1,visited);// East
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v,vector<int>(v,1)); // 1- > water 0 -Land
    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;
      graph[x][y]=0;
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
    int number_of_island=0;
    vector<vector<bool>>visited(v,vector<bool>(v,false));
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(graph[i][j]==0 && visited[i][j]==false)
            {
                number_of_island++;
                drawTreeforComponent(graph,i,j,visited);
            }
        }
    }
    cout<<number_of_island;
    return 0;
}