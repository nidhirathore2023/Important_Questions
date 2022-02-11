#include<iostream>
#include<stack>
using namespace std;/* Example - ddddiiii (n size )= 543216789 (n+1 size)
                                 dddddddd = 987654321
                                 iiiiiiii = 123456789     
 */
int main() // T.C =O(n) ,S.C = O(n)
{
    string s;
    cin>>s;
    int n=s.size();
    stack<int>st;// use to store elements in reverse order
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='d')// if d-> then increase and push 
        {
            c++;
            st.push(c);
        }
        else if(s[i]=='i')// if i -> increase and push and print all values in stack
        {
            c++;
            st.push(c);
            while(!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
        }
    }
    c++;// increase and push
    st.push(c);
    while(!st.empty())// print all remaining values 
    {
        cout<<st.top();
        st.pop();
    }
    return 0;
}