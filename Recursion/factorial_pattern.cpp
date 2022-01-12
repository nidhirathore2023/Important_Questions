#include<iostream>
using namespace std;
void display(int n)
{
    if(n<1)
    {
        return;
    }
    static int pv=0,nt=1;
    int k=pv+nt;
    pv=nt;
    nt=k;
    cout<<k<<" ";
    display(n-1);
    
}
int main()
{
    int n;
    cin>>n;
    cout<<"0 1 ";
    display(n-2);
    return 0;
}