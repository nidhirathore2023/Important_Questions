#include<stack>
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else if(s[i]=='C')
        {
            st.pop();
        }
        else if(s[i]=='D')
        {
            int a=st.top();
            st.push(a*2);
        }
        else if(s[i]=='+')
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            st.push(a+b);
        }
    }
    cout<<st.top()<<" ";
    return 0;
}