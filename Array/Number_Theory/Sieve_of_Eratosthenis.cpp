#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // find first n prime numbers ----> brute force check each element = O(n*n)
    // this is effecient apporach use vector to store whether number is having factor other then it self and 1
    int n;
    cin>>n;
    vector<bool>flag(n,false);// initailize with false 
    for(int i=2;i<=n;i++)
    {
        if(flag[i]==false)// check if not visited before 
        {
            for(int j=i*i;j<=n;j=j+i)// start with square EX--> 5 will start from 25 (10,15,20 are checked by 2 and 3) and 5 itself is non-prime number if it is not prime number it must have upadte by elemnts previous to it
            {
                flag[j]=true;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(flag[i]==false)// print prime numbers
        {
            cout<<i<<" ";
        }// TC =O(n) --> each element is visited once 
    }
    return 0;
}