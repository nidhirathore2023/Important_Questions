#include<iostream>
#include<vector>
using namespace std;
const vector<string> code={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};// define string for codes
vector<string> kpc(string s)
{
    if(s.size()==0)
    {
        vector<string>ans;
        ans.push_back("");
        return ans;
    }
// 678
    char c=s[0];// get 6
    string temp_s=s.substr(1,s.size()-1);//get combinations of  78
    vector<string>ans=kpc(temp_s);

    vector<string>final_ans;
    
    int idx=c-'0';// get index of 6
    string code_at_idx=code[idx];// string at 6
    for(int i=0;i<code_at_idx.size();i++)// loop for string length 
    {
        char temp=code_at_idx[i];
        for(auto x:ans)// for combinations of 78
        {
         final_ans.push_back(temp+x);// add every character of string at 6 with combination of 78
        }
    }
    return final_ans;
}
int main()
{
    string s;
    cin>>s;
    vector<string>ans=kpc(s);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}