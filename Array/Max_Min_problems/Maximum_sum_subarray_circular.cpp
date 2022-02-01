#include<iostream>
using namespace std;
int kadane (int a[],int n)
{
    int sum=a[0];
    int mx=a[0];
    for(int i=1;i<n;i++)
    {
        sum=max(sum+a[i],a[i]);// add to older array Or start using new subarry
        mx=max(mx,sum);
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //find simple mx
    int simple_mx=kadane(a,n);
    if(simple_mx <0)// if all element are negative then return from here
    {
        cout<<simple_mx;
        return 0;
    }

    int total_sum=0;
    for(int i=0;i<n;i++)
    {
        total_sum+=a[i];//find total sum
        a[i]=-a[i];// invert the elements (reversing the sign )
    }
    
    int comple_mx=kadane(a,n);// again find  max for inverted array

    int wrap=total_sum+comple_mx;// add total and max(inverted array)
    cout<<max(simple_mx,wrap);// returnn max of wrapped and unwrapped array

    return 0;
}