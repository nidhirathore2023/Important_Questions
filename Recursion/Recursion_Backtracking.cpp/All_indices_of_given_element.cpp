#include<iostream>
#include<vector>
using namespace std;
vector<int> all_occurences(int a[],int c,int n,int k)
{
    if(n==c)
    {
        vector<int>ans;
        return ans;
    }
    vector<int>ans;
    if(a[c]==k)
    {
        ans.push_back(c);
    }
    vector<int>val_from_next=all_occurences(a,c+1,n,k);
    for(int i:val_from_next)
    {
        ans.push_back(i);
    }
    return ans;
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
 int k;
 cin>>k;
 vector<int>ans=all_occurences(a,0,n,k);
 for(int x:ans)
 {
     cout<<x<<" ";
 }
 return 0;
}