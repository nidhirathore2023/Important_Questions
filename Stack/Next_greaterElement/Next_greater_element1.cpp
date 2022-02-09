#include<iostream>
#include<vector>
#include<stack>
using namespace std;// T.C = O(n)
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())// if empty ---> no  next greater element 
        {
            ans[i]=-1;
        }
        else if(a[i]<st.top())// if at top of stack
        {
            ans[i]=st.top();
        }
        else
        {
            while(!st.empty() && a[i]>=st.top())//  pop till-> stack become empty Or get greater elment in stack
            {
                st.pop();
            }
            if(st.empty())// loop ends due to stack is empty
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();// if get greater element
            }
        }
        st.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}