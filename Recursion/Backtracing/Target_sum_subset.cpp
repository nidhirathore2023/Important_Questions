#include<iostream>
#include<vector>
using namespace std;
void target_sub_set(vector<int>a,int c,int cul_sum,int sum,string ans)
{
    if(a.size()==c)// counter became equal to array size 
    {
        if(sum==cul_sum)// sum is also equal
        {
            cout<<ans<<"\n";// print answer
        }
        return;
    }

    target_sub_set(a,c+1,cul_sum+a[c],sum,ans+to_string(a[c])+" ");// element included 
    target_sub_set(a,c+1,cul_sum,sum,ans);// element not included
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    target_sub_set(a,0,0,sum,"");
    return 0;
}