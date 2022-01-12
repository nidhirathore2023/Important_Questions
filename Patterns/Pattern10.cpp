#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=n/2+2;
    int i;
    for( i=0;i<n/2;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<i+1;
        for(int j=0;j<t;j++)
        {
            cout<<" ";
        }
        t=t-2;
        cout<<i+1;
        cout<<"\n";
    }
    for(int i=0;i<n/2+1;i++)
    {
        cout<<" ";
    }
    cout<<i+1<<"\n";
    i=i+1;
    t=t+2;
      for( ;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        cout<<i+1;
        for(int j=0;j<t;j++)
        {
            cout<<" ";
        }
        t=t+2;
        cout<<i+1;
        cout<<"\n";
    }
    return 0;
}