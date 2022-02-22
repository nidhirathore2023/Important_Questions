#include<iostream>
#include<vector>
using namespace std;
void flood_fill(vector<vector<int>>a,int row,int col,string ans,vector<vector<bool>>visited)
{
    if(row<0 || col<0 ||row==a.size() || col == a[0].size() || a[row][col]==1 || visited[row][col]==true)
    {
        return ;
    }
    if(row==a.size()-1 && col==a[0].size()-1)
    {
        cout<<ans<<" ";
        return ;
    }

    visited[row][col]=true;
    flood_fill(a,row-1,col,ans+"l",visited);
    flood_fill(a,row,col-1,ans+"t",visited);
    flood_fill(a,row+1,col,ans+"d",visited);
    flood_fill(a,row,col+1,ans+"r",visited);
    visited[row][col]=false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    flood_fill(a,0,0,"",visited);
    return 0;
}