#include<iostream>
#include<stack>
#include<vector>
// Find the span between higher previous stock price than  current element
using namespace std;// T.C = O(n) , S.C = O(n)
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int pge[n];// find ----> previous greater element 
    stack<int>st;
    for(int i=0;i<n;i++)// loop forward
    {
        while(!st.empty() && a[i]>=a[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            pge[i]=-1;
        }
        else
        {
            pge[i]=st.top();
        }
        st.push(i);
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(pge[i]==-1)// if no previous element present -> gap =(i+1)
        {
           ans.push_back(i+1);
        }
        else
        {
            ans.push_back(i-pge[i]);// if present -->  i-pge[i]
        }
    }

    for(int i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}