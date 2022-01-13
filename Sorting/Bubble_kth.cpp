#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int p=a[j];
                a[j]=a[j+1];
                a[j+1]=p;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    return 0;
}