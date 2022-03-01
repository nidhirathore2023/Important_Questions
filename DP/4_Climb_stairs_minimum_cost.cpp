/*Given the cost for climbing each step need to find minimum cost
Conditions-
1-can start from either 0 or 1 index
2- can take one or two steps at a time
*/
#include<iostream>
using namespace std;
int min_cost(int cost[],int n)
{
    int dp[n+1];
    dp[0]=0;//since we can start form either of one and zero index there value is initialised to zero 
    dp[1]=0;
    for(int i=2;i<=n;i++)//Direction of problem -------->>>>>>
    {
        dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
    }
    return dp[n];
}
int main()//TC= O(n) , SC= O(n)
{
    int n;
    cin>>n;
    int cost[n];
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    cout<<min_cost(cost,n);
}