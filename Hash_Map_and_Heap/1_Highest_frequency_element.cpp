#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_map<char,int>m;
    for(int i=0;i<s.size();i++)// count frequency 
    {
        m[s[i]]++;
    }
    int mx=0;
    char ans;
    for(auto x:m)// find majority character 
    {
        if(x.second>mx)
        {
            mx=x.second;
            ans=x.first;
        }
    }
    cout<<ans<<" ";
    return 0;
}