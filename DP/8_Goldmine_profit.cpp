#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int Gold_mine(vector<vector<int>>a,int n,int m)
{
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=m-1;j>=0;j--) // loop from backward  (COLUMN-WISE)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(j==m-1) // last column 
            {
                dp[i][j]=a[i][j];
            }
            else if(i==0) // first row 
            {
              dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+a[i][j];
            }
            else if(i==n-1) // last row 
            {
              dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+a[i][j];
            }
            else // else
            {
              dp[i][j]=max(max(dp[i][j+1],dp[i-1][j+1]),dp[i+1][j+1])+a[i][j];
            }
        }
    }

    int mx_profit=INT_MIN;
    for(int i=0;i<n;i++)
    {
       mx_profit=max(mx_profit,dp[i][0]);
    }

    return mx_profit;// maximum in first column will give the maximum value that can be obtain (if start from that particular index in first column )
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<Gold_mine(a,n,m);
    
    return 0;
}



/*
A[][]
6 6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

Dp[][]
26 24 21 14 12 2
31 26 23 17 6 4
28 27 21 11 10 6
29 25 25 13 8 2
33 26 23 18 6 4
32 30 18 17 9 1

33
*/