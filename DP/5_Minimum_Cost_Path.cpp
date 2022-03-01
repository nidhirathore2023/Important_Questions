#include<iostream>
#include<vector>// Simple problem -> DP
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
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=n-1;i>=0;i--)//direction of problem <<<<<<<<<<------------
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)// right last corner
                {
                    dp[i][j]=a[i][j];
                }
            else if(i==n-1)//last row
            {
                dp[i][j]=dp[i][j+1]+a[i][j];
            }
            else if(j==m-1)// last column
            {
                dp[i][j]=dp[i+1][j]+a[i][j];
            }
            else// else cases
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+a[i][j];
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}