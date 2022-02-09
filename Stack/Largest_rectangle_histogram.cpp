#include<iostream>
#include<vector>
#include<stack>
using namespace std;//T>C= O(n) S.C = O(n)->left and right
int Largest_rectangle(int a[],int n)
{
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;// use to maintain order of elements ------- >store indexes of next smaller elements 
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            left[i]=0;
        }
        else 
        {
            while(!st.empty()&& a[i]<=a[st.top()])// till stack is empty or smaller element is not found 
            {
                st.pop();
            }
            if(st.empty())// if exit loop due to empty stack 
            {
                left[i]=0;
            }
            else//if get smaller element 
            {
                left[i]=st.top()+1;// -------->>>> note 
            }
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            right[i]=n-1;
        }
        else
        {
            while(!st.empty() && a[i]<=a[st.top()])// till stack is empty or smaller element is not found 
            {
                st.pop();
            }
            if(st.empty())// if exit loop due to empty stack 
            {
                right[i]=n-1;
            }
            else//if get smaller element 
            {
                right[i]=st.top()-1;
            }
        }
        st.push(i);
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int area=(right[i]-left[i]+1)*a[i];// find area =>  width =(r-l+1) , height =>a[i]
        mx=max(mx,area);
    }
    return mx;
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
     cin>>a[i];
  }
   cout<<Largest_rectangle(a,n);
    return 0;
}