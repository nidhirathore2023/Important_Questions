#include<iostream>
#include<vector>
using namespace std;
int number_of_largest_subsquence(int a[],int n)
{
    vector<int>dp(n,1);
    vector<int>count(n,1);// keep count of number of longest subsquence till now
    int omax=0;
    for(int i=0;i<n;i++)
    {
        int mx=0;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                if(mx<dp[j])
                {
                    mx=dp[j];
                    count[i]=count[j];//else continue with older
                }
                else if(mx==dp[j])// if found add value of found index
                {
                    count[i]+=count[j];
                }
            }   
        }
        dp[i]=mx+1;
        omax=max(omax,dp[i]);
    }
    int ans=0;
    /*
    Important test case
    7
    10 20 9 50 41 60 55
    ans=4
    */
    for(int i=0;i<n;i++)
    {
        if(dp[i]==omax)
        {
            ans+=count[i];// add value 
        }
    }
    return ans;
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
    cout<<number_of_largest_subsquence(a,n);
    return 0;
}