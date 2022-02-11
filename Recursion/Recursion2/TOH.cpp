#include<iostream>
using namespace std;
void toh(int n,char a,char b,char c)
{
   if(n>1)
   {
       toh(n-1,a,c,b);
       cout<<"Move "<<a<<" to "<<c<<"\n";
       toh(n-1,b,a,c);
   }
}
int main()
{
    int n;
    cin>>n;
    char a='A',b='B',c='C';
    toh(n,a,b,c);
    return 0;
}