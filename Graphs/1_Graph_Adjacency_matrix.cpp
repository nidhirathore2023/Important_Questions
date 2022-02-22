#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>>g[v+1];// vertice and weight & Base 1 indexing 
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
        // undirected Graph
    }
    for(int i=1;i<=v;i++)// 1  Based indexing 
    {
        cout<<i;
        for(auto x:g[i])
        {
            cout<<"-->"<<x.first<<","<<x.second;
        }
        cout<<"\n";
    }
    return 0;
}