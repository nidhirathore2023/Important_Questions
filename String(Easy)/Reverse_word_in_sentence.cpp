#include<iostream>
#include<vector>
using namespace std;
vector<string> reverse_sentence(string s,int n)
{
    string st="";
    int j=0;
    vector<string>ans;
    for(int i=0;i<n;i++)
    { 
        if(s[i]==' ')
        {
            cout<<st<<"\n";
            ans.push_back(st);
           st="";
            j=0;
        }
        st+=s[i];
    }
     ans.push_back(st);
     
    return ans;
}
int main()
{
   //"java is best"  ---> "best is java"
   string s;
    getline(cin,s);
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    cout<<"\n";
    vector<string>ans=reverse_sentence(s,n);
    for(int i=ans.size()-1;i>=0;i--)//using vector to store strings (at indices ) --> then print them in reverse order
    {
        cout<<ans[i];
    }
    return 0;
}