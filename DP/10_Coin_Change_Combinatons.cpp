#include<iostream>
#include<vector>
using namespace std;
/*
Combinations-
2 3 5 (infinite pool --> can be repeated)----> Different from target subset ---> in this repetition is allowed 
target -7
Combination-(223,25)(not permutaion ) -> 2

*/
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int target;
    cin>>target;
    vector<int>dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++) // loop far every element of subset
    {
        for(int j=a[i];j<target+1;j++) // fill target 
        {
            
            dp[j]+=dp[j-a[i]]; 
            
        }
    }
    cout<<dp[target];
    return 0;
}