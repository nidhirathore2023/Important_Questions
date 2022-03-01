#include<iostream>
using namespace std;
int subtraction_any_base(int n1,int n2,int b)
{
    int c=0;
    int p=1;
    int ans=0;

    while(n1>0 || n2>0 || c>0)
    {
       int d1=n1%10;
       int d2=n2%10;

       n1=n1/10;
       n2=n2/10;

       if(c==1)// treat carry
       {
           d1--;
           c=0;
       }

       if(d1<d2)// carry 
       {
           d1=d1+b;
           c=1;
       }

       int d=d1-d2;

       ans+=d*p;
       p=p*10;

    }
    return ans;
}
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int b;
    cin>>b;
    cout<<subtraction_any_base(n1,n2,b);
    return 0;
}