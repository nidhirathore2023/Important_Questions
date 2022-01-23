#include<iostream>
#include<string>
#include<vector>
using namespace std;
string largest_substr(string s)
//naive approach --->> finding all substrings and check pallindrome T.C = O(n^3)
//approach --> DP T.C= O(n^2)
{
     int n=s.size();
        if(n==1)
        {
            return s;
        }
        string ans;
        int st;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int mx=0;
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;j++,i++)
            {
                if(g==0)
                {
                    dp[i][j]=true;
                }
                else if(g==1)
                {
                    if(s[i]==s[j])
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
                    if(dp[i+1][j-1]==true && s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j])
                {
                    mx=max(mx,g+1);
                    st=i;
                    
                }
            }
        
        }
        ans=s.substr(st,mx);
        return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<largest_substr(s);
    return 0;
}