#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    double v1=(double)a.first/(double)a.second;
    double v2=(double)b.first/(double)b.second;
    return v1>v2;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int pr,wt;
        cin>>pr>>wt;
        a.push_back({pr,wt});
    }
    sort(a.begin(),a.end(),cmp);
    int tot_wt;
    cin>>tot_wt;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].second<=tot_wt)
        {
          ans+=a[i].first;
          tot_wt-=a[i].second;
          continue;
        }
        double temp=(double)a[i].first/(double)a[i].second;
        ans+=temp*tot_wt;
        tot_wt=0;
        break;
    }
    cout<<"Total Profit "<<ans;
    return 0;
}