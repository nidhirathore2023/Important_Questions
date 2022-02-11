#include<iostream>
#include<vector>
#include<string>
using namespace std;
// S.C =O(n*n+1) ---> n calls --> print result not get answer
const vector<string> codes={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
void kpc(string s,string ans)
{
    if(s.size()==0)// if string is empty print 
    {
        cout<<ans<<" ";
        return ;
    }
    char c=s[0];// get first character 
    string temp=s.substr(1,s.size()-1);// get rest of string

    int  idx=c-'0';
    string code_at_idx=codes[idx];// get string at first character ------ > 
    for(int i=0;i<code_at_idx.size();i++)// for string 
    {
        char t=code_at_idx[i];// get charceter 
        kpc(temp,ans+t);// n---> calls (not two )
    }
}
int main()
{
    string s;
    cin>>s;
    kpc(s,"");
    return 0;
}