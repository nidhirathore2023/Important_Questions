#include<iostream>
using namespace std;
void premuation(string s,string ans)
{
    if(s.size()==0)// print when size is zero
    {
        cout<<ans<<" ";
    }
    for(int i=0;i<s.size();i++)// for everyy element give rest of array
    {
        char s1=s[i];// any element
        string s2=s.substr(0,i);// string  before element 
        string s3=s.substr(i+1,s.size());// string after element 
        premuation(s2+s3,ans+s1);// call for rest of string and add character to answer
    }
}
int main()
{
    string s;
    cin>>s;
    premuation(s,"");
    return 0;
}