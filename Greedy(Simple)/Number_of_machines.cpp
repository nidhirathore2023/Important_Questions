#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>a;
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        a.push_back({s,e});
    }
    sort(a.begin(),a.end(),cmp);
    vector<bool>visited(n);
    int c=0;
    int number_of_machines=0;
    while(c!=n-1)// till all are visited
    {
        int currend=-1;
        for(int i=0;i<n;i++)
        {
          if(visited[i]==false)
          {
            if(currend<a[i][0])
            {
              currend=a[i][1];
              c++;
              visited[i]=true;
            }
          }
        }
        number_of_machines++;// number of machines
    }
    cout<<number_of_machines;
    return 0;
}