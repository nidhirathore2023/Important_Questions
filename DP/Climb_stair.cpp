#include<iostream>
#include<vector>
using namespace std;//TC = O(n) SC = O(n)
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)//direction of problem ------>>>>>>
    {
        if(i==1)
        {
            dp[i]=dp[i-1];
        }
        else if(i==2)
        {
            dp[i]=dp[i-1]+dp[i-1];
        }
        else
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
    }
    cout<<dp[n];
    return 0;
}