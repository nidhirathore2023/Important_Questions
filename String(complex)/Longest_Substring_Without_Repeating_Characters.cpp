#include<iostream>
#include<unordered_map>
using namespace std;
int longest_substring(string &s,int n)
{
    int mx=0;
    unordered_map<char,int>m;
    int i=0,j=0;
    while(j<s.size())
    {
        m[s[j]]++;
        if(m.size()==j-i+1)
        {
            mx=max(mx,j-i+1);
        }
        else if(m.size()<j-i+1)
        {
            while(m.size()!=j-i+1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return mx;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    cout<<longest_substring(s,n);
    return 0;
}