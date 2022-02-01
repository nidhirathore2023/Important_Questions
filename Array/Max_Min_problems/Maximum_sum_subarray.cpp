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
    int temp_sum=a[0],mx=a[0];// initalise both with first element 
    for(int i=1;i<n;i++)
    {
        temp_sum=max(temp_sum+a[i],a[i]);// ---> Continue with ald array Or start with new  subarray array
        mx=max(temp_sum,mx);
    }
    cout<<mx;
    return 0;
}