#include<iostream>
#include<string>
using namespace std;
void encoding(string s,string ans)
{
    if(s.size()==0)
    {
        cout<<ans<<" ";
    }
    if(s.size()==1)
    {
        if(s[0]=='0')
        {
            return ;
        }
        else
        {
            int c=s[0]-'0';
            char code=char('a'+c+1);
            ans=ans+code;
            cout<<ans<<" ";
        }
    }
    else
    {
        if(s[0]=='0')
        {
            return ;
        }
        else
        {
            int c=s[0]-'0';
            char code=char('a'+c+1);
            char c1=s[0];
            string temp=s.substr(1,s.size()-1);
            encoding(temp,ans+code);
        }

        string ch12=s.substr(0,2);
        string code12=s.substr(2,s.size()-1);

        int ch12=stoi(ch12);
        if(ch12<=26)
        {
            char code=char('a'+ch12+1);
            encoding(code12,ans+code);
        }
    }
}
int main()
{
    string s;
    cin>>s;
    encoding(s,"");
    return 0;
}