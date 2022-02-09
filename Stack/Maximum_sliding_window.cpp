#include<iostream>
#include<stack>
using namespace std;// T.C =O(n)  S.C = O(n)
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int nge[n];// -------> used to store indices of Next Greater
    stack<int>st;
    for(int i=n-1;i>=0;i--)// Find Next Greater Element 
    {
        while(!st.empty()&& a[i]>=a[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            nge[i]=n;// if no next greater element ---> n (because -1 will give wrong result when we compare it with sliding window size)
        }
        else
        {
            nge[i]=st.top();
        }
        st.push(i);
    }
    // Checking for different windows 
    for(int i=0;i<=n-k;i++)// till------> last window
    {
        int j=i; // i---> Starting point of window 
                // j----> Current position  in Window 
        while(nge[j]<k+i)// if next greater element of current element if within window side
        {
            j=nge[j];// increase current element to that index
        }
        cout<<a[j]<<" ";// current position will give Maximum of Current Window 
    }
    return 0;
}