#include<iostream>
using namespace std;
void func(int n)// Recursion with multiple calls
{
    if(n==0)
    return ;
    
    cout<<"Pre "<<n<<"\n";// 1
    func(n-1);            // 2
    cout<<"In "<<n<<"\n";// 3
    func(n-1);           //4
    cout<<"Post "<<n<<"\n";//5
}
int main()
{
    int n;
    cin>>n;
    func(n);
    return 0;
}