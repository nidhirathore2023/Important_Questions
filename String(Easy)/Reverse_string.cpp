#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n/2;i++)
    {
      char a=s[i];
      s[i]=s[n-i-1];
      s[n-i-1]=a;
    }
    cout<<s;
    return 0;
}