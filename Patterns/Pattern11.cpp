#include<iostream>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    int t=n-2;
    int c;
    for(int i=0;i<n/2;i++)
    {
        c=1;
        for(int j=0;j<=i;j++)
        {
          cout<<c;
          c++;
        }
        for(int j=0;j<t;j++)
        {
            cout<<" ";
            c++;
        }
        for(int j=0;j<=i;j++)
        {
            cout<<c;
            c++;
        }
        t=t-2;
        cout<<"\n";
    }
    t=1;
    int k;
    if(n%2==0)
    {
        k=n/2;
        k=k-1;
    }
    else
    {
        k=n/2;
    }
    for(int i=k;i<n;i++)
    {
       c=1;
       for(int j=0;j<n-i-1;j++)
       {
           cout<<c;
           c++;
       }
       for(int j=0;j<t;j++)
       {
           cout<<" ";
           c++;
       }
       for(int j=0;j<n-i-1;j++)
       {
           cout<<c;
           c++;
       }
       t=t+2;
       cout<<"\n";
    }
    return 0;
}