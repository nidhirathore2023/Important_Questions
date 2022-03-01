#include<iostream>
using namespace std;
int main()
{
   unsigned int a,b;;
    cin>>a>>b;
    unsigned int ans=0;
    while(b>0)
    {
      
      if(b & 1) // Or b%2!=0  ===> to  check wheather number is odd 
      {
        ans=ans+a;
      }
      a=a << 1; //  a=a*2 (double first number)
      b=b >> 1; //  b=b/2 (halves second number)
    }
    cout<<ans;
    return 0;
}