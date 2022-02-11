#include<iostream>
using namespace std;
int first_occurenc(int a[],int c,int n,int k)
{
    if(n==c)
    {
        return -1;
    }
    if(a[c]==k)// if get return 
    return c;
    
    int fi= first_occurenc(a,c+1,n,k);// if not get next call
    return fi;// return value 
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
 int k;
 cin>>k;
 cout<<first_occurenc(a,0,n,k);
 return 0;
}