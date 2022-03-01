#include<iostream>
#include<math.h>
using namespace std;

//Any base to Decimal base
int any_base_to_decimal(int n,int b)
{
 int ans=0;
 int mul=0;
 while(n>0)
 {
     int rem=n%10;
     ans=ans+(pow(b,mul)*rem);
     n=n/10;
     mul++;
 }
 return ans;
}

//Decimal to any base
int decimal_to_any_base(int n,int b)
{
  int ans=0;
  int p=1;
  while(n>0)
  {
    int rem=n%b;
    ans+=rem*p;
    n=n/b;  
    p=p*10;
  }
  return ans;
}


// Any to any base
int any_to_any_base(int n,int b1,int b2)
{
    int t1=any_base_to_decimal(n,b1);
    int t2=decimal_to_any_base(t1,b2);
    return t2;
}

int main()
{
    int num;
    cin>>num;
    int b1,b2;
    cin>>b1>>b2;
    cout<<any_to_any_base(num,b1,b2);
    return 0;
}