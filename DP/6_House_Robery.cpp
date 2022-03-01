#include<iostream>
using namespace std;
int max_profit(int a[],int n)//T.C = O(n) ,SC= O(n)
{
    if(n==1)
    {
        return a[0];// if size is ---> 1 
    }
    if(n==2)
    {
        return max(a[0],a[1]);//if size is ----> 2
    }
    int dp[n];
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-2]+a[i],dp[i-1]);//recurrence relation 
    }
    return dp[n-1];
}
int main()
{
    int  n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<max_profit(a,n);// constraint ----> cannot rob two adjacent houses
    return 0;
}