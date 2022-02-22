#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> stair_case(int n,string ans,vector<string>& final_ans)
{
    if(n==0)// if n==0 --> valid -----> print 
    {
        final_ans.push_back(ans);
        return final_ans;
    }
    if(n<0)// if n-> negative --> invalid case
    {
       return final_ans;
    }
     stair_case(n-1,ans+"1",final_ans);// call for 1 step
     stair_case(n-2,ans+"2",final_ans);// call for 2 step
     stair_case(n-3,ans+"3",final_ans);// call for 3 step
     return final_ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string> ans;
    stair_case(n,"",ans);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}