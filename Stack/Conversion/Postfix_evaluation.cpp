#include<iostream>
#include<string>
#include<stack>
#include<vector>// T.C = O(n) S.C =O(n)
using namespace std;// Multi-Digits ----> if single digit this will also work or traverse stack till end
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
    for(int i=0;i<n;i++)// traverse left-> right (v2-v1)
    {
        if(s[i]!="+"&& s[i]!="-"&& s[i]!="*" && s[i]!="/")
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
                st.push(v2+v1);
            }
            else if(s[i][0]=='-')
            {
                st.push(v2-v1);
            }
            else if(s[i][0]=='*')
            {
                st.push(v2*v1);
            }
            else if(s[i][0]=='/')
            {
                st.push(v2/v1);
            }

        }
    }
    cout<<st.top()<<" ";
    return 0;
}