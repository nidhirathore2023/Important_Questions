#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(int a,stack<int>&st)//T.C =O(n) ,S.C =O(n)(call stack) ------> convert to linked list for O(1)
{
    if(st.empty())
    {
        st.push(a);
    }
    else
    {
        int t=st.top();
        st.pop();
        insert_at_bottom(a,st);

        st.push(t);
    }

}
void reverse(stack<int>&st)
{
    if(st.empty())
    {
        return ;
    }
    int a=st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(a,st);
}
int main()
{
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    reverse(s1);
    cout<<s1.top()<<" ";
    s1.pop();
    cout<<s1.top()<<" ";
    s1.pop();
    cout<<s1.top()<<" ";
    s1.pop();
    cout<<s1.top()<<" ";
    s1.pop();
    cout<<s1.top()<<" ";
    s1.pop();
    return 0;
}