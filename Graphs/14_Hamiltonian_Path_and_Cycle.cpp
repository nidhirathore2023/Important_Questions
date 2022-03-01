#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void Hamiltonian_Path_cycle(int v,vector<int>graph[],int src,unordered_set<int>&visited,string psf,int original_src)
{
   if(visited.size()==v-1) // if visited size is one less than total vertices 
   {
       cout<<psf;
       bool cycle_found=false;
       for(auto x:graph[src]) // check for cycle
       {
           if(x==original_src)
           {
             cycle_found=true;
           }
       }
       if(cycle_found)
       {
           cout<<"*\n";
       }
       else
       {
           cout<<".\n";
       }
   }

   visited.insert(src);
   for(auto x:graph[src]) //Visit 
   {
       if(!visited.count(x))
       {
        Hamiltonian_Path_cycle(v,graph,x,visited,psf+to_string(x)+" ",original_src);
       }
   }
   visited.erase(src);// Unvisit
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
    int src;
    cin>>src;
    unordered_set<int>visited;// use set  visited array -> size in O(n)
    Hamiltonian_Path_cycle(v,graph,src,visited,to_string(src)+" ",src);
    return 0;
}
/*

Hamiltonian Path (visit all vetrices once ) & Cycles (visit all vertices once --> Return to source vertice)
7 9
0 1
0 6
5 6
1 5
1 2
5 4
2 4
2 3
4 3

0


0 1 2 3 4 5 6 * ---> Cycle 
0 6 5 1 2 4 3 . --->Path
0 6 5 1 2 3 4 .---> Path
0 6 5 4 3 2 1 *--->Cycle
*/