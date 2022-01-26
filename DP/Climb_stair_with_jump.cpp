#include<iostream>
#include<vector>
using namespace std;//TC = O(n) , SC = O(n)
int main()
{
    int n;
    cin>>n;
    int jump[n];
    for(int i=0;i<n;i++)
    {
        cin>>jump[i];
    }
    vector<int>dp(n+1,0);//Direction of solving problem  <<<<<------------
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<jump[i] && i+j+1<dp.size();j++)
        {
            dp[i]+=dp[i+j+1];// adding values according to given jumps 
        }
    }
    cout<<dp[0];
    return 0;
}