#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int back_to_number(vector<int>a)
{
    int n=0;
    for(int i=0;i<a.size();i++)
    {
        n=n*10+a[i];
    }
    return n;
}
void reverese(vector<int>&a)
{
    int n=a.size();
    for(int i=0;i<n/2;i++)
    {
        int t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    while(n<0)
    {
    int r=n=n%10;
    a.push_back(r);
    n=n/10;
    }
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    reverese(a);
    int r=-1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            r=i;
        }
    }
    if(r==-1)
    {
     reverese(a);
     int n2=back_to_number(a);
      if(n2>n)
      {
          cout<<n2<<" ";
      }
      else
      {
          cout<<"-1";
      }
      return 0;
    }
    int next=r;
    for(int i=r;i<n;i++)
    {
        if(a[r-1]<a[i]&& a[r]>a[i])
        {
            next=i;
        }
    }
    int p=a[r-1];
    a[r-1]=a[next];
    a[next]=p;
    sort(a.begin()+r,a.end());
    int n2=back_to_number(a);
      if(n2>n)
      {
          cout<<n2<<" ";
      }
      else
      {
          cout<<"-1";
      }
    return 0;
}