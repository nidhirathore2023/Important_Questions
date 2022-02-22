#include<iostream>
#include<vector>
using  namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>g(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;//undirected Graph 
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}