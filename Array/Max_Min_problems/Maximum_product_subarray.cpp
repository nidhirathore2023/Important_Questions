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
    int min_tillNow =a[0];
    int mx=a[0];
    int max_tillNow=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<0)
        {
            int t=min_tillNow;
            min_tillNow=max_tillNow;
            max_tillNow=t;
        }
        max_tillNow=max(max_tillNow*a[i],a[i]);
        min_tillNow=min(min_tillNow*a[i],a[i]);
        mx=max(mx,max_tillNow);
    }
    cout<<mx;
    return 0;
}