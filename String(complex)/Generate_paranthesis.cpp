#include<iostream>
#include<vector>
using namespace std;
void generate(int n,int c,int o,string s,vector<string>&op)
{
    if(n==o&&n==c)
    {
        op.push_back(s);
        return;
    }
    if(o<n)
    {
        generate(n,c,o+1,s+'(',op);
    }
    if(c<o)
    {
        generate(n,c+1,o,s+')',op);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string>ans;
    generate(n,0,0,"",ans);
    for(auto x:ans)
    {
        cout<<x<<"   ";
    }
    return 0;
}