#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double s=1;
    float k=1;
    for(int i=0;i<n;i++)
    {
        int nt;
        if(i%2==0)
        {
            nt=3/2*k;
            s+=nt;
        }
        else
        {
            nt=2*k;
            s+=nt;
        }
        k=nt;
    }
    cout<<s<<" ";
    return 0;
}

/*    1 term = 1
      2 term = 2*1 =2
      3 term = 3/2*2 = 3
      4 term = 2*3 = 6
      5 term = 3/2*6 = 9
      6 term = 2* 9 = 18
      7 term = 3/2 *18 = 27

      odd = 3/2 *last element
      even = 2* last element

*/