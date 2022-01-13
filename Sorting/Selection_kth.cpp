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
    int m;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        m=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[m])
            {
                m=j;
            }
        }
        int p=a[i];
        a[i]=a[m];
        a[m]=p;
    }
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    return 0;
}