#include<iostream>
#include<climits>
#include<vector>
using namespace std;
/*
Unbounded 0_1 Knapsack---> every iteam can be taken more than once ---> 1-D array (Similar to ---> Coin Change - Combinations & Permutations )
In this case => any can be used --(order doesn't matter ---> Find profit )

5
wt[]=1 2 3 4 5
profit[]=10 15 45 30 14
capacity= 7

DP
0 10 20 45 55 65 90 100
*/
int main()
{
    int n;
    cin>>n;
    int wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int profit[n];
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    int capacity;
    cin>>capacity;
    vector<int>dp(capacity+1,0);
    dp[0]=0;
    for(int i=1;i<capacity+1;i++)
    {
        int mx=0;
        for(int j=0;j<n;j++)
        {
            if(wt[j]<=i)
            {
                int curr=dp[i-wt[j]]+profit[j];
                mx=max(mx,curr);
            }
        }
        dp[i]=mx;
    }
    for(int i=0;i<capacity+1;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<dp[capacity];
    return 0;
}