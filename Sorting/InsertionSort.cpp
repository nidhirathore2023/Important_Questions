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
    for(int i=0;i<n;i++)
    {
       int t=a[i];
       int j=i-1;
       while(j>=0 && a[j]>t)
       {
           a[j+1]=a[j];
           j--;
       }
       int p=a[j+1];
       a[j+1]=t;
       t=p;
    }
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    return 0;
}