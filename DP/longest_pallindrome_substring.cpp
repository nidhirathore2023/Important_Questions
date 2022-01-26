#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,j;
    int start,mx=0;
    int n=s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int g=0;g<dp.size();g++)
    {
        for( i=0,j=g;j<dp.size();j++,i++)
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
                start=i;
            }
        }
    }
    cout<<s.substr(start,mx);
    cout<<mx;
    return 0;
}