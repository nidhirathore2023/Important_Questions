#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=i;j+t>=0;j--)
        {
            cout<<j+1+t;
        }
        t=t+1;
        cout<<"\n";
    }
    return 0;
}