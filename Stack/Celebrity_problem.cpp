#include<iostream>
#include<stack>
using namespace std;
const int n=4;
void Celebrity(int a[][n])
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }
    while(st.size()>=2)// till satck have 2  or more elements 
    {
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(a[i][j]==1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int pot=st.top();// potiential candidate but not compulsory he is celebrity
    for(int i=0;i<n;i++)
    {
        if(i!=pot)
        {
            if(a[pot][i]==1 || a[i][pot]==0)
            {
                cout<<"none";
                return ;
            }
        }
    }
   cout<<pot;
}
int  main()
{
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    Celebrity(a);// Only one person can be Celebrity (not more) Or there can be no celebrity as well
    return 0;
}