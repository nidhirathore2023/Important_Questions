#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    unordered_map<int,int>map;
    for(int i=0;i<m;i++)
    {
        map[b[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(map[a[i]])
        {
            cout<<a[i]<<" ";
            map.erase(map[a[i]]);
        }
    }

    /*
    a ={1,1,2,2,3,4} ( can be unsorted )
    b={1,2,2,3,3,5}
    
    ans ={1,2,3}
    common in both based on occuerance in a array
    */
    return 0;
}