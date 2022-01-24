#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int st,ed;
        cin>>st>>ed;
        a.push_back({st,ed});
    }
    sort(a.begin(),a.end(),cmp);
    int sel=0;
    int curr=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i].first>=curr)
        {
            curr=a[i].second;
            sel++;
        }
    }
    cout<<"No of selected activities "<<sel;
    return 0;
}