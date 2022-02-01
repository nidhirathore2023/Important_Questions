#include<iostream>
#include<vector>
using namespace std;
void LCS_print(string s1,string s2,int n,int m)
{
    //finding lcs 
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=n,j=m;
    // tracing dp table to get lcs string 
    while(i>0 && j>0)//travese from back 
    {
      if(s1[i-1]==s2[j-1])
      {
          ans+=s1[i-1];
          i--;
          j--;
      }
      else if(dp[i-1][j]>dp[i][j-1])
      {
          i--;
      }
      else
      {
          j--;
      }
    }
    int mm=ans.size();
    for( i=0;i<(mm)/2;i++)//reverse the the string obtained
    {
      char c=ans[i];
      ans[i]=ans[mm-i-1];
        ans[mm-i-1]=c;
    }
    cout<<ans;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    LCS_print(s1,s2,n,m);
    return 0;
}