#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    unordered_map<int,int>mp;
    for(int i=0;i<m;i++)
    {
        mp[a[0][i]]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[a[i][j]]==i)
            {
                mp[a[i][j]]=i+1;
                if(i==n-1 && mp[a[i][j]]==n)
                {
                    cout<<a[i][j]<<" ";
                }
            }
        }
    }
    return 0;
}