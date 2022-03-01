#include<iostream>
#include<vector>
using namespace std;
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
    vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));// Repeation is not allowed --> Use 2-D array 
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<target+1;j++)
        {
            if(i==0 && j==0)// Fisrt row and first column (not with first row)
            {
                dp[i][j]=true;
            }
            else if(i==0) // first row 
            {
                dp[i][j]=false;
            }
            else if(j==0) // first column
            {
                dp[i][j]=true;
            }
            else // else 
            {
                if(dp[i-1][j]==true) // if rest of team scores  runs ---> directly true
                {
                    dp[i][j]=true;
                }
                else
                {
                    int val=a[i-1]; // value of current element i-1----> dp 1 --> a 0
                    if(j>=val)  // bats only if have enough balls
                    {
                        if(dp[i-1][j-val]==true) // if it bats and score target sum -> tue 
                        {
                          dp[i][j]=true;
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                    else
                    {
                        dp[i][j]=false;
                    }   
                }
            }
        }
    }

    if(dp[n][target]==true) 
    {
        cout<<"PRESENT";
    }
    else
    {
        cout<<"NOT_PRESENT";
    }
    return 0;
}