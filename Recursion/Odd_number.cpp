#include<iostream>
using namespace std;
void Odd(int n)
{
    if(n==0)
    {
        return ;
    }
    Odd(n-1);
    if(n%2!=0)
    {
        cout<<n<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    Odd(n);
    return 0;
}