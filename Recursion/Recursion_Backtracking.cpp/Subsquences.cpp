#include<iostream>
#include<vector>
using namespace std;//SC= O(2^n*n)---> store in a vector -------> one call (of function )
vector<string> sub(string s)
{
    if(s.size()==0)
    {
        vector<string>ans;
        ans.push_back("");// size of vector will be 1 but string is "" (empty)
        return ans;
    }
    char c=s[0];
    string temp_s=s.substr(1,s.size()-1); 
    vector<string>temp_ans=sub(temp_s);// get subsquences of sub(bc) ---> one call 
    vector<string>final_ans;

    for(auto x:temp_ans)
    {
        final_ans.push_back(x);// _subsqueneces of sub(bc)
    }
    for(auto x:temp_ans)
    {
        final_ans.push_back(c+x);// a+subsqueneces of sub(bc)
    }
    return final_ans;// return ans
}
int main()
{
    string s;
    cin>>s;
    vector<string>ans=sub(s);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}