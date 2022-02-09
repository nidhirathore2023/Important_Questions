#include<iostream>
#include<string>
#include<stack>
using namespace std;//T.C = O(n) ,S.C =O(1)--> one element at a time in stack
/*example-

s="the sky is blue";
s="blue is sky the"

s="  hello world  "        ------------> ignore the useless spaces 
s="world hello"

s="a good   example"
s="example good a"


*/
string reverse(string s)
{
    stack<string>st;
    string temp="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')// if space then push 
        {
            if(temp!="")// if temp is not empty -------> useless space 
            {
                st.push(temp);
                temp="";// initialise to empty
            }
        }
        else
        {
            temp+=s[i];// include characters
        }
    }
    if(temp!="")// check  last case because loop is terminated 
    {
        st.push(temp);
    }
    temp="";
    while(!st.empty())
    {
        temp+=st.top();// get strings 
        st.pop();
        if(!st.empty())// also add space if it is not last character
        {
            temp+=' ';
        }
    }
    return temp;
}
int main()
{
    string s;
    getline(cin,s);// to take string with space 
    cout<<s<<"\n";
    cout<<reverse(s);
    return 0;
}