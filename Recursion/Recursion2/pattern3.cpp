#include<iostream>
using namespace std;
void display(int n)
{
    static int t=0;
    if(n==t)
    {
        return ;
    }
    cout<<(t+1)*(t+1)<<"+";
    t++;
    display(n);
    
}
int main()
{
    int n;
    cin>>n;
    display(n);
    return 0;
}