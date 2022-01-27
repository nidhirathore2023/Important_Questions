#include<iostream>
#include<vector>
#include<climits>
using  namespace std;
int min_moves(int jump[],int n)
{
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--)//Direction of problem <<<<<<<<<<-------------
    {
        int mi=INT_MAX;//get minimum steps
        for(int j=0;j<jump[i] && i+j+1<dp.size();j++)// compare for given jumps
        {
            if(dp[i+j+1]!=-1)// for null-----> cannnot go anywhere || for 0 ---->  needs zero steps to reach i position
            {
                mi=min(mi,dp[i+j+1]);
            }
        }
        if(mi==INT_MAX)// if do not have path to reach there
        {
          dp[i]=-1;
        }
        else
        {
            dp[i]=mi+1;// total steps ------ >>>  (min(i1,i2,i3)+1)
        }
    }
    return dp[0];
}
int main()
{
    int n;
    cin>>n;
    int jump[n];
    for(int i=0;i<n;i++)
    {
        cin>>jump[i];
    }
    cout<<min_moves(jump,n);
    return 0;
}