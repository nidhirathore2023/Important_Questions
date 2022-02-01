#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int n;
    cin>>n;
    cin>>a>>b;

           /*Principal of Inclusion Exclusion */

   // find number divisible between 1 to n divisible by a and b

    int c1=n/a;// number divisible between 1 to n divisible by a 
    int c2=n/b;// number divisible between 1 to n divisible by a 
    int c3=n/(a*b);// number divisible between 1 to n divisible by  both a,b
    cout<<(c1+c2-c3);//answer
    return 0;
}