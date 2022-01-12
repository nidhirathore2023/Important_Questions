#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=n+2;
    int k=n;
    int kk=n;
    char a='A';
   for(int i=0;i<n-1;i++)
   {
       char ans=a+kk-1;
       for(int j=0;j<i;j++)
       {
           cout<<" ";
       }
       cout<<ans;
       for(int j=0;j<t;j++)
       {
           cout<<" ";
       }
       cout<<ans<<"\n";
       t=t-2;
       kk--;
   }
   for(int i=0;i<n-1;i++)
   {
       cout<<" ";
   }
   cout<<"A";
    return 0;
}