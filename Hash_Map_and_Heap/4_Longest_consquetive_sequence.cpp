#include<iostream>
#include<climits>
#include<unordered_set>
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

    unordered_set<int>set;
    for(int i=0;i<n;i++)
    {
        set.insert(a[i]);
    }
      
    
    int curr;
    int end_point;
    int b=1;
    int max_length=0;
    for(int i=0;i<n;i++)
    {
        if(!set.count(a[i]-1))// start from smallest number in sequence 
        {
            curr=a[i];
            b=1;
            while(set.count(curr+1))
            {
             b++;
             curr++;
            }
        }
      if(max_length<b)
      {
        max_length=b;
        end_point=curr;
      }
    }

    int starting_point=end_point-max_length+1;// get sarting point 
    while(max_length--)
    {
        cout<<starting_point<<" ";// print values
        starting_point++;
    }

    return 0;
}