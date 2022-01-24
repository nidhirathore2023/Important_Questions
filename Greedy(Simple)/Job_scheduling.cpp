#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int pr,de;
        cin>>pr>>de;
        a.push_back({pr,de});
    }
    sort(a.begin(),a.end(),[](pair<int,int>a,pair<int,int>b){ return a.first>b.first;});
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,a[i].second);
    }
    int ans=0;
    vector<int>fill(mx,0);
    for(int i=0;i<n;i++)
    {
        int j=a[i].second;
        while(j>=0 && fill[j]!=0)
        {
            j--;
        }
        if(fill[j]==0 && j>=0)
        {
            fill[j]=a[i].second;
            ans+=a[i].first;
        }

    }
    cout<<"Maximum Profit "<<ans;
    return 0;
}
