#include<iostream>
using namespace std;
int main()
{
                 /* Euclid Algorithm */

    // Find GCD (HCF) of a and b
    /* example-  24 ,42 
    42-24=18
    24-18=6
    18-6=12
    12-6=6;
    6-6=0
    ------> HCF=6
    
    using modules 
    42%24=18
    24%18=6
    18%6=0
    -------->HCF  = 6
    */
    int a,b;
    cin>>a>>b;
    while(b!=0)
    {
        int rem=a%b;
        a=b;
        b=rem;
    }
    cout<<a;
    return 0;
}