#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int m=n-2;
    int b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    // b is subset of a ----> find thte next greater element of b in a
    stack<int>st;
    unordered_map<int,int>mp;// next greatest element of every element in a
    for(int i=n-1;i>=0;i--)// size of a (bigger array)
    {
        if(st.empty())
        {
            mp[a[i]]=-1;
        }
        else if(a[i]<st.top())
        {
            mp[a[i]]=st.top();
        }
        while(!st.empty()&& a[i]>st.top())
        {
            st.pop();
        }
        if(st.empty())
        {
            mp[a[i]]=-1;
        }
        else
        {
            mp[a[i]]=st.top();
        }
        st.push(a[i]);
    }
    vector<int>ans;
    for(int i: b)
    {
        ans.push_back(mp[i]);// push next greater element of elements 
    }
    for(int i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}
/*Input: b = [4,1,2], a = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of b is as follows:
- 4 is underlined in a = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in a = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in a = [1,3,4,2]. There is no next greater element, so the answer is -1.*/
