#include<iostream>
#include<stack>
using namespace std;
int precedence(char c)
{
    if(c=='+')
    return 1;
    else if(c=='-')
    return 1;
    else if(c=='*')
    return 2;
    else if(c=='/')
    return 2;

    return -1;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<string>infix;
    stack<string>prefix;

    for(int i=0;i<n;i++)
    {
        if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
           string t;
           t+=s[i];
           prefix.push(t);
           infix.push(t);
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
               string in1=infix.top();
               infix.pop();
               string in2=infix.top();
               infix.pop();

               string pr1=prefix.top();
               prefix.pop();
               string pr2=prefix.top();
               prefix.pop();

               infix.push('('+in2+s[i]+in1+')');
               prefix.push(s[i]+pr2+pr1);            
          
        }
    }
    cout<<"Infix"<<" "<<infix.top()<<"\n";
    cout<<"Prefix"<<" "<<prefix.top()<<"\n";
    return 0;
}