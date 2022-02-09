#include<iostream>
#include<vector>
#include<string>
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
    if(c=='/')
    return 2;

    return -1;
}
int calculation(int a,int b,char c)
{
    if(c=='+')
    {
        return (a+b);
    }
    else if(c=='-')
    {
        return (a-b);
    }
    else if(c=='*')
    {
        return (a*b);
    }
    else if(c=='/')
    {
        return (a/b);
    }
    return 0;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<int>num;
    stack<char>op;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')// if opening bracket 
        {
            op.push(s[i]);
        }
        else if(s[i]>='0' && s[i]<='9')// if number 
        {
            num.push(s[i]-'0');
        }
        else if(s[i]==')')
        {
            while(op.top()!='(')// pop and process till get openeing bracket
            {
                int v1=num.top();
                num.pop();
                int v2=num.top();
                num.pop();
                char c=op.top();
                op.pop();
                int ans=calculation(v2,v1,c);
                num.push(ans);
            }
            op.pop();//-----> pop opening bracket 
        }
        else if(s[i]=='+'|| s[i]=='-'|| s[i]=='*'|| s[i]=='/' )
        {
            while(!op.empty() && op.top()!='(' && precedence(s[i])<=precedence(op.top()))      //-------> if op is not empty or top of op stack is not openeing bracket and precedence of current element is smaller and equal to top of op stack
            {
                int v1=num.top();
                num.pop();
                int v2=num.top();
                num.pop();
                char c=op.top();
                op.pop();
                int ans=calculation(v2,v1,c);
                num.push(ans);
            }
            op.push(s[i]);
        }
    }
    while(!op.empty())// some elements left -->  a+b  
    {
        int v1=num.top();
        num.pop();      
        int v2=num.top();
        num.pop();
        char c=op.top();
        op.pop();
        int ans=calculation(v2,v1,c);
        num.push(ans);        
     }
    cout<<num.top();
    return 0;
}