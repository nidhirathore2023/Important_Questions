/*
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
*/
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        q.push(a[i]);
        if(a[i]==0)
        {
            q.push(0);
        }
        a[i]=q.front();
        q.pop();
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}