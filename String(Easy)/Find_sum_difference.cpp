#include<iostream>
using namespace std;
/* Can be done without using map or extra array because only one character is different in both strings

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.



Example 2:

Input: s = "", t = "y"
Output: "y"

*/
char findTheDifference(string s, string t) {
        int a=0,b=0;
        for(int i=0;i<s.size();i++)
        {
            a+=(int)s[i];
        }
        for(int i=0;i<t.size();i++)
        {
            b+=(int)t[i];
        }
        return char(b-a);
    }
int main()
{
    cout<<findTheDifference("abcd","abcde");
    return 0;
}