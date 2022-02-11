#include<iostream>
using namespace std;
int last_occurence(int a[],int c,int n,int k)
{
    if(n==c)
    {
        return -1;
    }
    int li=last_occurence(a,c+1,n,k);// call--> till the end 
    if(li==-1)// if work is not done your team 
    {
        if(a[c]==k)// if you can do it return you index --> you have done the work
        {
            return c;
        }
        else
        {
            return -1;// else --> work is not done 
        }
    }
    else// if work was done by your team then ----> simply give credit to them
    {
        return li;
    }
    
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
 cout<<last_occurence(a,0,n,k);
 return 0;
}