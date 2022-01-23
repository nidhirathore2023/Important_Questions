#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    //approach ---> modify sorting 
    vector<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        s.push_back(a);
    }
    sort(s.begin(),s.end(),[](string &a,string &b){return a+b>b+a;});//directly create compare function
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    return 0;
}