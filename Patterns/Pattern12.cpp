#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l=0,h=1;
    int ans;
    cout<<1<<"\n";
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            ans=l+h;
            l=h;
            h=ans;
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}