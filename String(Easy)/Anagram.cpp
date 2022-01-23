#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    if(n!=m)
    {
        cout<<"not anagram ";
        return 0;
    }
    vector<int>c(256,0);
    for(int i=0;i<n;i++)
    {
        c[s1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        c[s2[i]]--;
    }
    bool p=false;
    for(int i=0;i<256;i++)
    {
        if(c[i]!=0)
        {
            p=true;
        }
    }
    if(p)
    {
        cout<<"not anagram ";
    }
    else
    {
        cout<<"anagram ";
    }
    return 0;
}