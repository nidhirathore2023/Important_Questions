#include<iostream>
#include<vector>
using namespace std;// S.C =O(n*n+1)--> print directly --> two calls of function
void  sub(string s,string ans)
{
    if(s.size()==0)
    {
        cout<<ans<<" ";
        return;
    }
    string temp=s.substr(1,s.size()-1);// get rest of string 
    char c=s[0];// first index

    sub(temp,ans+"");// not added
    sub(temp,ans+c);// added 
}
int main()
{
    string s;
    cin>>s;
    sub(s,"");
    return 0;
}