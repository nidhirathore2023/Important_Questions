#include<iostream>
#include<climits>
using namespace std;
//(naive solution ---> find frequecy of every element TC= O(n^2))
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int c[256];
    for(int i=0;i<256;i++)// using counting array 
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        c[s[i]]++;
    }
    int mx=INT_MIN;
    char ans;
    for(int i=0;i<256;i++)
    {
        if(c[i]>mx)
        {
            mx=c[i];
            ans=i;
        }
    }
   cout<<ans;
    return 0;
}