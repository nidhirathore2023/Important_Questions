#include<stack>
#include<iostream>
#include<vector>
using namespace std;// Circular Next Greater  Element 
int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        st.push(a[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            ans[i]=-1;
        }
        else if(a[i]<st.top())
        {
            ans[i]=st.top();
        }
        while(!st.empty() && a[i]>=st.top())
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}