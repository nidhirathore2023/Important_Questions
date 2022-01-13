#include<iostream>
using namespace std;
float fact(int n)
{
    if(n==1)
    {
       return 1;
    }
    return fact(n-1)*n;
}
float power(int x,int c)
{
    float ans=1;
    for(int i=0;i<c;i++)
    {
       ans=ans*x;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    float c=1;
    float s=1;
    for(int i=1;i<n;i++)
    {
        c=1;
        c=c*i;
        float a=power(x,c);
        float b=fact(c);
        if(i%2==0)
        {
            s+=(a/b);
        }
        else
        {
            s-=(a/b);
        }
        
    }
    cout<<"sum "<<s;
    return 0;
}