#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    

    unordered_map<int,int>m1;

    for(int i=0;i<n;i++)
    {
        m1[a[i]]++;
    }
    

    for(int i=0;i<m;i++)
    {
        if(m1[b[i]])
        {
           cout<<b[i]<<" ";
           if(m1[b[i]]==1)
           {
             m1.erase(b[i]);
           }
           else
           {
               m1[b[i]]--;
           }
           
        }
    }

/*
a= {3 2 1 1 2 4}
b= {1 2 1 2 3 4}

ans ={1 2 1 2 3 4 } --> intersection according to

*/
    return 0;
}