#include<iostream>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.size();//TC = O(n)
    s1=s1+s1;
    if(s1.find(s2)>=0 && s1.find(s2)<n)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}