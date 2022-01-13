#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float c=1;
    float s=0.0;
    for(int i=0;i<n;i++)
    {
        s=s+(1.0/(c*c));
        c++;
    }
    cout<<"sum "<<s;
    return 0;
}