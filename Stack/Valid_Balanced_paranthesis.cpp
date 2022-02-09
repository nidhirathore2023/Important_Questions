#include<iostream>
#include<stack>
using namespace std;//T.C =O(n) , S.C =O(n) (stack)
/*
exp= “[()]{}{[()()]()}”  => 1
exp = “[(])”   => 0
exp = “(())” ==> 0
exp= "()(()))))" =>0--------> edge case
*/
bool valid_OR_balanced_paranthesis(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' ||s[i]=='[' ||s[i]=='{' )// push opening brackets
        {
            st.push(s[i]);
        }
        else if(s[i]==')') // if closing bracket
        {
            if(st.empty())// if stack became empty -----> ()))))))
            {
                return false;
            }
            else if(st.top()!='(')// if top is not opening bracket of same type  
            {
                return false;
            }
            else // if get valid bracket pop it
            {
                st.pop();
            }
        }
        else if(s[i]=='}')
        {
            if(st.empty())
            {
                return false;
            }
            else if(st.top()!='{')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else if(s[i]==']')
        {
            if(st.top()!='[')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<valid_OR_balanced_paranthesis(s);
    return 0;
}