#include<iostream>
#include<vector>
using namespace std;//Longest common Subsquence (total number of subsquences ---- > 2^n (take number or not))
// Different from subarray ---- > total number of subarray ----> (n(n+1))/2
// subarray (abc) -----> a,ab,abc,b,bc,c -- >(total=6)
int LCS(string s1,string s2,int n,int m)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)// Direction of problem ------>
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])//-------> note that s[0] (for i=1) --> s[i-1]
            {
                dp[i][j]=1+dp[i-1][j-1];// if equal
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);// if not equal 
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    cout<<LCS(s1,s2,n,m);//Tabulation 
    return 0;
}