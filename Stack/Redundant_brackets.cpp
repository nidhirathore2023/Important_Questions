#include<iostream>
#include<stack>
using namespace std;//T.C =O(n)
// Duplicate case is taken care of 

/*
((a+b)) = 1 ->redundant 
(a+(b)/c) = 1
(a+b*(c-d)) = 0
()a =1
((a+b)) =1
*/
bool redundant(string s)
{
    stack<char>st;
    bool ans=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='/') // if any operator exist between brackets then---> not redundant 
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')// if not operator present 
            {
                ans=true;// redundant 
                break;
            }
            while(st.top()=='+' ||st.top()=='-' ||st.top()=='*' ||st.top()=='/')// else pop till ---> opening brackets
            {
                st.pop();
            }
            st.pop();// pop opening brackets
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<redundant(s);
    return 0;
}