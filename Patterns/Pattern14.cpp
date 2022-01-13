#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=(2*n-1)/2;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    int k=2*n-1;
     for(int i=(2*n-1)/2;i<(2*n-1);i++)
    {
        for(int j=0;j<=k-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=k-i-1;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    } 
    return 0;
}