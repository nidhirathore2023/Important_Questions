#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int n=s.size();
    int c=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='\n'||s[i]=='\t'||s[i]==' ')
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}