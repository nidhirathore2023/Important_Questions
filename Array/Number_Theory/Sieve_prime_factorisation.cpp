#include<iostream>
#include<vector>
using namespace std;
void prime_factor_print(int n)
{
    vector<int>smallest_prime_factor(n);// store smallest prime factor for each number
    for(int i=1;i<=n;i++)
    {
      smallest_prime_factor[i]=i;// initialise to numbers 
    }
    for(int i=2;i<=n;i++)
    {
      if(smallest_prime_factor[i]==i)// if number not visited -->  number at this index is a prime number at it will mark rest of numbers
      {
          for(int j=i*i;j<=n;j=j+i)// for marking other number 
          {
              if(smallest_prime_factor[j]==j)// if number is already update by some prime number before then do not change smallest_prime factor --> because number which marked it must be smaller than current prime number
              {
                  smallest_prime_factor[j]=i; // update smallest prime factor
              }
          }
      }
    }
    /*
    a[] =  1 2 3 4 5 6 7 8 9 10
    spf[] =1 2 3 2 5 2 7 2 3  2
    */
    while(n!=1)
    {
        cout<<smallest_prime_factor[n]<<" ";
        n=n/smallest_prime_factor[n];
    }
    /*
    n= 6;
    spf[6]=2;

    **********
    spf[6] = 2--> print 
    n=n/spf[n]
    n=6/spf[6]
    n=3;

    spf[3] = 3 --->print 
    n=n/spf[n]
    n=3/spf[3]
    n=1;
    */
    return;
}
int main()
{
    int n;
    cin>>n;
    prime_factor_print(n);
    return 0;
}