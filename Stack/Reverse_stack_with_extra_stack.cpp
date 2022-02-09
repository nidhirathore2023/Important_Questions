#include<iostream>
#include<stack>
using namespace std;//T.C = O(n) S.C =o(n)
int main()
{
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    stack<int>s2;
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    cout<<s2.top()<<" ";
    s2.pop();
    cout<<s2.top()<<" ";
    s2.pop();
    cout<<s2.top()<<" ";
    s2.pop();
    cout<<s2.top()<<" ";
    s2.pop();
    cout<<s2.top()<<" ";
    s2.pop();
    return 0;
}