#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void print(int a[],int n)
{
    // Similar to longest increasing subsquence
    vector<int>dp(n);
    int omax=0;
    for(int i=0;i<n;i++)
    {
        int mx=0;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j])
            {
                mx=max(mx,dp[j]);
            }
        }
        dp[i]=mx+1;
        if(omax<dp[i])
        {
            omax=dp[i];//get length of maximum subsquence 
        }
    }
    queue<pair<int,string>>q;// use BFS concept
    for(int i=0;i<n;i++)
    {
        if(dp[i]==omax)
        {
         q.push({i,to_string(a[i])});// if having more than one subsquence
        }
    }
    
    while(!q.empty())
    {
        int idx=q.front().first;
        string s=q.front().second;
        q.pop();//get elements
        if(idx==0)
        {
            cout<<s<<" \n";//print ---- > base condition
        }
        for(int j=0;j<idx;j++)// get all indexes 
        {
            if(dp[idx]-1==dp[j] && a[j]<=a[idx])
            {
                string t=to_string(a[j]);
                q.push({j,t+" "+s});// push string by concatenating current value
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    print(a,n);
    return 0;
}