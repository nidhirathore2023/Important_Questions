#include<iostream>
#include<queue>
using namespace std;
// T.C = O(n) , S.C = O(k)
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
    priority_queue<int,vector<int>,greater<int>>q;// use min_heap 

    // push value k values in heap
    for(int i=0;i<k;i++)
    {
        q.push(a[i]);
    }


    for(int i=k;i<n;i++)
    {
        // if top is smaller than top pop it and push a[i]
        if(q.top()<a[i])
        {
            q.pop();
            q.push(a[i]);
        }
    }
    
    // queue have size k with k largest element 
    for(int i=0;i<k;i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}