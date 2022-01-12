#include<iostream>
using namespace std;
void Even(int n)
{
    if(n==0)
    {
        return ;
    }
    Even(n-1);
    if(n%2==0)
    {
        cout<<n<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    Even(n);
    return 0;
}