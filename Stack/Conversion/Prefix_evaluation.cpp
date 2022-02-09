#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;// T.C = O(n) S.C =O(n)
int main()
{
    int n;
    cin>>n;
    vector<string>s;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        s.push_back(t);
    }
    stack<int>st;
    for(int i=n-1;i>=0;i--)// traverse right-> left (v1-v2)
    {
        if(s[i]!="+" &&s[i]!="-" && s[i]!="*" &&s[i]!="/" )
        {
            st.push(stoi(s[i]));
        }
        else
        {
            int v1=st.top();
            st.pop();
            int v2=st.top();
            st.pop();
            if(s[i][0]=='+')
            {
                st.push(v1+v2);
            }
            else if(s[i][0]=='-')
            {
                st.push(v1-v2);
            }
            else if(s[i][0]=='*')            {
                st.push(v1*v2);
            }
            else if(s[i][0]=='/')
            {
                st.push(v1/v2);
            }
        }
    }
    cout<<st.top()<<" ";
    return 0;
}