/*Longest_increasing_subsquence


  a-> 10 20 9 33 50 41 60 80  3
Longest_increasing_subsquence=> (10,20,33,50,60,80) or (10,20,33,41,60,80) ---> length -> 6
*/

#include<iostream>
#include<vector>
using namespace std;
int Longest_increasing_subsquence(int a[],int n)
{
    vector<int>dp(n);//  **** Imp---> dp[i] store ->  length of longest increasing subsquence  which ends with a[i]
    int omax=0;
    for(int i=0;i<n;i++)//Direction of problem ----------->
    {
        int mx=0;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j])// check if we can include the current element to make incresing subsequence ends with a[i]
            {
                mx=max(mx,dp[j]);
            }
        }
        dp[i]=mx+1;
        omax=max(omax,dp[i]);// calculate maximum length 
      
    }
    return omax;
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
    cout<<Longest_increasing_subsquence(a,n);
    return 0;
}