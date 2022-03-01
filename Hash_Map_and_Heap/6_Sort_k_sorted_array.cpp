#include<iostream>
#include<queue>
using namespace std;
/*
9 
2 3 1 4 6 7 5 8 9
2
1 2 3 4 5 6 7 8 9


array is k sorted 
every element is shift almost k left or right of array


T.C = O(nlogk)
S.C = O(k)
*/
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

    priority_queue<int,vector<int>,greater<int>>q; // min queue
    for(int i=0;i<k+1;i++)
    {
        q.push(a[i]);
    }
    for(int i=k+1;i<n;i++)
    {
        cout<<q.top()<<" ";
        q.pop();
        q.push(a[i]);
    }

    for(int i=0;i<k+1;i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}