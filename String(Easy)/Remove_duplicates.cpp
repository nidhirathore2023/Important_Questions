/*
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int j;
    int n=s.size();
    int in=0;
    for(int i=0;i<n;i++)
    {
        for( j=0;j<i;j++)// checking if this character present before
        {
            if(s[i]==s[j])
            break;
        }
        if(i==j)//if not present then add
        {
            s[in]=s[i];
            in++;
        }
    }
    for(int i=0;i<in;i++)
    {
        cout<<s[i];
    }
    return 0;
}

*/
// TC= O(n^2) for this solution can use map to check if element appeared before


#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    //TC= O(n) 
    // SC =O(256)= O(1)
    string s;
    cin>>s;
    int j;
    int n=s.size();
    int in=0;
    unordered_map<char,int>m;
    for(int i=0;i<n;i++)
    {
        if(m.find(s[i])==m.end())
        {
            m[s[i]]++;
            s[in]=s[i];
            in++;
        }
    }
    for(int i=0;i<in;i++)
    {
        cout<<s[i];
    }
    return 0;
}