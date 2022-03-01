#include<iostream>
#include<vector>
using namespace std;
/*
Permutations -
2 3 5 (infinite pool --> can be repeated)----> Different from target subset ---> in this repetition is allowed 
target -7
Permutation -(223,232,322,52,25)(not permutaion ) -> 5

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
    for(int i=0;i<target+1;i++) // loop for targets
    {
        for(int j=0;j<n;j++)// for elements in given array ---> Permutation are allowed
        {
            if(a[j]<=i)
            {
                dp[i]+=dp[i-a[j]];
            }
        }
    }
    cout<<dp[target];
    return 0;
}