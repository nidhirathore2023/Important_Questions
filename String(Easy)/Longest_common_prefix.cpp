#include<vector>
#include<iostream>
#include<climits>
using namespace std;
string longest_prefix(vector<string>s,int n)
{
    string res;
    char c;
    int mi=INT_MAX;
    for(auto &x:s)
    {
        if(mi>x.size())
        {
            mi=x.size();
        }
    }
    for(int i=0;i<mi;i++)
    {
        c=s[0][i];
            for(int j=1;j<s.size();j++)
            {
                if(c!=s[j][i])
                {
                    return res;
                }
            }
            res.push_back(c);
    }
        return res;
}
int main()
{
    vector<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string re;
        cin>>re;
        s.push_back(re);
    }
    cout<<longest_prefix(s,n);//TC = O(N*M) ---> M= size of smallest string , N= size of  vector(total number of strings)
    return 0;
}