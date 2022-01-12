#include<iostream>
using namespace std;
int display(int n)
{
    if(n<=1)
    {
        return n;
    }
   return display(n-1)+display(n-2);
    
}
int main()
{
    int n;
    cin>>n;
    cout<<display(n);
    return 0;
}