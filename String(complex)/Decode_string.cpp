#include<iostream>
#include<string>
using namespace std;
// appraoch ---> use recursion to solve inner problems
string solve(int &i,string s)
{
    int n=s.size();
    string num="";
    string ans="";
    for( ;i<n;i++)
    {
        if(s[i]=='[')
        {
            i=i+1;
            string rep=solve(i,s);
            for(int j=0;j<stoi(num);j++)
            {
                ans+=rep;
            }
            num="";
        }
        else if(s[i]==']')
        {
            return ans;
        }
        else if(s[i]>='0' &&s[i]<='9')
        {
            num+=s[i];
        }
        else
        {
            ans+=s[i];
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    int i=0;
    cout<<solve(i,s);
    return 0;
}