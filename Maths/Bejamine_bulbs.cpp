#include<iostream>
using namespace std;
/*
Initilally alll bulbs are OFF 
1 iteration - 1 multiples are toogled
2 iteration - 2 multiples are toogled
ans so on

if a bulb toggle evan times = OFF
else ON

Normal numbers have even factors (2n)
Example - 6
1*6=6
2*3=6
3*2=6
6*1=6


Perfect Squares have factors (2n+1)
4=2*2 ---> on extra 

*/
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i*i<=n)// print all perfect Squares
        {
            cout<<i*i<<" ";
        }
    }
    return 0;
}