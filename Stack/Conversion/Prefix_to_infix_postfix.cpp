#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<string>infix;
    stack<string>postfix;
    for(int i=n-1;i>=0;i--)// loop ------> Reverse
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            string in1=infix.top();
            infix.pop();
            string in2=infix.top();
            infix.pop();

            string po1=postfix.top();
            postfix.pop();
            string po2=postfix.top();
            postfix.pop();

            postfix.push(po1+po2+s[i]);
            infix.push('('+in1+s[i]+in2+')');//---------> only different in postfix  
        }
        else 
        {
            string t;
            t+=s[i];
            postfix.push(t);
            infix.push(t);
        }
    }
    cout<<"Postfix "<<postfix.top()<<"\n";
    cout<<"Infix  "<<infix.top()<<"\n";
    return 0;
}