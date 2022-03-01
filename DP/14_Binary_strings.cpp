#include<iostream>
using namespace std;
/*
Number of Binary string with length n such that not 0's are consecutive to each other 

4 variable can work not need of 2-D array
*/
int main()
{
    int n;
    cin>>n;
    int prev_0=1; // one string possible -> 0
    int prev_1=1;// one string posiible -> 1
    int cur_0;
    int cur_1;
    for(int i=2;i<=n;i++)
    {
        cur_0=prev_1;
        cur_1=prev_1+prev_0;

        prev_0=cur_0;
        prev_1=cur_1;
    }
    cout<<cur_0+cur_1<<" ";// Sum of cur_0 and cur_1 
    return 0;
}