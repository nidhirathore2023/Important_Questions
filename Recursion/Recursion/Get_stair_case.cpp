#include<iostream>
#include<vector>
using namespace std;
vector<string> stair_case(int n)
{
    if(n==0)// valid case push 
    {
        vector<string>ans;
        ans.push_back("");
        return ans;
    }
    else if(n<0)// negative invalid case  
    {
        vector<string>ans;
        return ans;
    }
    vector<string>n1=stair_case(n-1);// n-1
    vector<string>n2=stair_case(n-2);//n-2
    vector<string>n3=stair_case(n-3);// n-3
    
    vector<string>final_ans;

    for(auto i:n1)
    {
        final_ans.push_back("1"+i);// add 1
    }
    for(auto i:n2)
    {
        final_ans.push_back("2"+i);// add 2
    }
    for(auto i:n3)
    {
        final_ans.push_back("3"+i);// add 3
    }
    return final_ans;// return all steps
}
int main()
{
    int n;
    cin>>n;
    vector<string>ans=stair_case(n);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}