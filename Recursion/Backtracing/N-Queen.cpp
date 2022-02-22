#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool is_safe(int row,int col,vector<vector<int>>grid)
{
    for(int i=row,j=col;i>=0;i--)// upward 
    {
        if(grid[i][j]==1)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0; i--,j--)// left digonal
    {
        if(grid[i][j]==1)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<=grid.size();i--,j++)// right digonal
    {
         if(grid[i][j]==1)
        {
            return false;
        }
    }

    return true;
}
void n_queen(int row,vector<vector<int>>grid,string ans)// row wise- call -----> for every column
{
    if(row==grid.size() )
    {
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<grid.size();i++)
    {
        if(is_safe(row,i,grid))
        {
            grid[row][i]=1;// make true
            n_queen(row+1,grid,ans+to_string(row)+"-"+to_string(i)+" ");
            grid[row][i]=0;// make false
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    n_queen(0,grid,"");
    return 0;
}