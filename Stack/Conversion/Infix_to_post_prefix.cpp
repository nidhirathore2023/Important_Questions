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
    stack<string>postfix;
    stack<string>prefix;
    stack<char>op;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
         op.push(s[i]);
        }
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')|| (s[i]>='A' && s[i]<='Z') )
        {
            string t;
            t+=s[i];
            postfix.push(t);
            prefix.push(t);
        }
        else if(s[i]==')')
        {
            while(op.top()!='(')
            {
                string p1=postfix.top();
                postfix.pop();
                string p2=postfix.top();
                postfix.pop();


                string po1=prefix.top();
                prefix.pop();
                string po2=prefix.top();
                prefix.pop();


                char c=op.top();
                op.pop();

                postfix.push(p2+p1+c);// postfix = ab+
                prefix.push(c+po2+po1);// prefix = +ab
            }
            op.pop();
        }
        else if(s[i]=='+'|| s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            while(!op.empty() && op.top()!='(' && precedence(s[i])<=precedence(op.top()))
            {
               string p1=postfix.top();
                postfix.pop();
                string p2=postfix.top();
                postfix.pop();


                string po1=prefix.top();
                prefix.pop();
                string po2=prefix.top();
                prefix.pop();


                char c=op.top();
                op.pop();

                postfix.push(p2+p1+c);
                prefix.push(c+po2+po1);
            }
            op.push(s[i]);
        }

    }
     while(!op.empty())
     {
        string p1=postfix.top();
        postfix.pop();
        string p2=postfix.top();
        postfix.pop();         


        string po1=prefix.top();
        prefix.pop();
        string po2=prefix.top();
        prefix.pop();


        char c=op.top();
        op.pop();

        postfix.push(p2+p1+c);
        prefix.push(c+po2+po1);
     }

     cout<<"Postfix"<<" "<<postfix.top()<<"\n";
     cout<<"Prefix"<<" "<<prefix.top()<<"\n";
    return 0;
}