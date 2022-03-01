#include<iostream>
#include<vector>
using namespace std;
// TC = O(n^2) , SC= O(n^2)
// similar to Target Subset Sum ----> in terms of repetition ->2-D array
int main()
{
    int n;
    cin>>n;
    int w[n],p[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
    int wt;
    cin>>wt;
    vector<vector<int>>dp(n+1,vector<int>(wt+1,0));
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            if(j>=w[i-1])// enough balls to bat
            {
                int rCap=j-w[i-1];//remaining ball if he bats
                if(dp[i-1][rCap]+p[i-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][rCap]+p[i-1];//if he bats profit by him + profit done by remaining team in remaining balls
                }
                else
                {
                    dp[i][j]=dp[i-1][j];//he doesn't bats
                }
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][wt];//maximum profit
   return 0;
}