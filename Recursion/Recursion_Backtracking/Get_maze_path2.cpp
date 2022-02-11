#include<iostream>
using namespace std;
void get_paths(int sr,int sc,int dr,int dc,string ans)// S.C =O(n*n+1) (stack) ---> 2 Calls
{
 if(sr==dr && sc==dc)// if reached destination print result
 {
     cout<<ans<<" ";
     return ;
 }
 if(sr<dr)
 {
     get_paths(sr+1,sc,dr,dc,ans+"h");// call for moving vertically
 }
 if(sc<dc)
 {
     get_paths(sr,sc+1,dr,dc,ans+"v");// call  for moving horizontally
 }
}
int main()
{
    int n,m;
    cin>>n>>m;
    get_paths(1,1,n,m,"");// 1- indexing for understaing purpose
    return 0;
}