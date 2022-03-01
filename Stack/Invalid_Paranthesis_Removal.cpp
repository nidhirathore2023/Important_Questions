#include<iostream>
#include<stack>
#include<unordered_set>
using namespace std;
// Valid Parathesis      +  Baktracking 
// Find minimal Removal  +  Find string after removal (unordered_set --> avoid duplicates)
int minimal_removal_required(string s)
{
  stack<char>st;
  for(int i=0;i<s.size();i++)
  {
      if(s[i]=='(') 
      {
          st.push(s[i]);
      }
      else if(s[i]==')')
      {
        if( st.empty())
        {
           st.push(s[i]);
        }
        else if(st.top()=='(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
      }
  }
  return st.size(); // give minimum removal
}

 //Backtracking 
void Invalid_removal(string s,int mi,unordered_set<string>&set)
{
  if(mi==0) // minimal removal is done
  {
    if(minimal_removal_required(s)==0)  // minimal removal required is zero -- > string is valid 
    { 
        if(!set.count(s)) // if not present in set than print and push to set -- >Avoid duplicates 
        {
          cout<<s<<"    ";
          set.insert(s);
        }
    }
  }
  for(int i=0;i<s.size();i++) // remove all indices at send left and right of string 
  {
    string left=s.substr(0,i);
    string right=s.substr(i+1,s.size());
    Invalid_removal(left+right,mi-1,set); // reduce mi= mi-1
  }
}

int main()
{
    string s="()())()";
    int mi=minimal_removal_required(s);// find minimal removal required to make string --- >Valid 
    unordered_set<string>set; // Avoid Duplicates
    Invalid_removal(s,mi,set); //Print Unique valid string after minimal removal
    return 0;
}