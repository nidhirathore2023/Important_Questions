#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=0;
    for(int i=0;i<n;i++)
    {
        cout<<" ";
    }
    cout<<"1\n";
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        cout<<i+1;
        for(int j=0;j<i+t;j++)
        {
            cout<<" ";
        }
        
        cout<<i+1<<"\n";
        t=t+1;
    }
     for(int i=n-1;i>1;i--)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        cout<<i;
        for(int j=0;j<i+t;j++)
        {
            cout<<" ";
        }
        
        cout<<i<<"\n";
        t=t-1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<" ";
    }
    cout<<"1\n";
    return 0;
}