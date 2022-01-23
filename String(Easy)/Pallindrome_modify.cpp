#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int n=s.size();
    string alt="";
    int in=0;
    for(int i=0;i<n;i++)
    {
            if(s[i]>='A'&& s[i]<='Z' )
            {
                alt+=s[i]+32;
                in++;
            }
            else if(s[i]>='a'&& s[i]<='z')
            {
                alt+=s[i];
                in++;
            }
    }
    for(int i=0;i<in;i++)
    {
        cout<<alt[i];
    }
    bool flag=false;
    for(int i=0;i<in;i++)
    {
      if(alt[i]!=alt[in-i-1])
      {
          flag=true;
          break;
      }
    }
    if(flag)
    {
        cout<<"Not pallindrome";
    }
    else
    {
        cout<<"Pallindrome ";
    }
    return 0;
}