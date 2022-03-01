#include<iostream>
using namespace std;
int max_profit(int a[],int n)
{
    if(n==1)
    {
        return a[0];
    }
    if(n==2)
    {
        return max(a[0],a[1]);
    }
    int dp[n];
    // in this case we will solve the problem two time 
    // 1 time ---> range ---> 0,n-2 (excluding last element) 
    // 2 time ---> range ---> 1,n-1 (excluding first element) 
    dp[0]=a[0];
    dp[1]=max(a[0],a[1]);
    for(int i=2;i<n-1;i++)//excluding last element
    {
     dp[i]=max(dp[i-2]+a[i],dp[i-1]);
    }
    int a1=dp[n-2];
    dp[1]=a[1];
    dp[2]=max(a[2],a[1]);
    for(int i=3;i<n;i++)//excluding first element
    {
     dp[i]=max(dp[i-2]+a[i],dp[i-1]);
    }
    int b1=dp[n-1];
    return max(a1,b1);
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
    cout<<max_profit(a,n);// constraints --- > no two adjacent houses can be robbed && 1st house is adjacent to last house ----> circular arrangement of houses
    return 0;
}