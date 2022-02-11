#include<iostream>
#include<string>
using namespace std;
void stair_case(int n,string ans)
{
    if(n==0)// if n==0 --> valid -----> print 
    {
        cout<<ans<<" ";
        return ;
    }
    if(n<0)// if n-> negative --> invalid case
    {
        return;
    }
    stair_case(n-1,ans+"1");// call for 1 step
    stair_case(n-2,ans+"2");// call for 2 step
    stair_case(n-3,ans+"3");// call for 3 step
}
int main()
{
    int n;
    cin>>n;
    stair_case(n,"");
    return 0;
}