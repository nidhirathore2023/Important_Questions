#include<iostream>
using namespace std;
void display(int n)
{
    static int t=0,nn=1;
    if(n==t)
    {
        return ;
    }
    cout<<nn<<"+";
    t++;
    nn=nn*2;
    display(n);
    
}
int main()
{
    int n;
    cin>>n;
    display(n);
    return 0;
}