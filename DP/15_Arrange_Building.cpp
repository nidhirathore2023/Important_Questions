#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int prev_b=1;
    int prev_s=1;
    int cur_b;
    int cur_s;
    for(int i=2;i<=<n;i++)
    {
        cur_b=prev_s;
        cur_s=prev_b+prev_s;

        prev_b=cur_b;
        prev_s=cur_s;
    }
    int count_of_one_size=prev_b+prev_s;
    int count_of_both_size=count_of_one_size*count_of_one_size;

    cout<<count_of_both_size;
    return 0;
}