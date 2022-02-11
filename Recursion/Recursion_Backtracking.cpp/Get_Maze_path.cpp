#include<iostream>
#include<vector>
using namespace std;
vector<string> get_paths(int sr,int sc,int dr,int dc)//S.C =O(2^n*n)(vector)----- > 1 Call
{
    if(sr==dr && sc==dc)// if reached destination return 
    {
        vector<string>ans;
        ans.push_back("");// one path --> donot move 
        return ans;
    }
    vector<string>h_paths;
    vector<string>v_paths;
    if(sr<dr)// move if source row is smaller than destination row
    {
        h_paths=get_paths(sr+1,sc,dr,dc);
    }
    if(sc<dc)// move if source column is smaller then destination column
    {
        v_paths=get_paths(sr,sc+1,dr,dc);
    }
    vector<string>all_paths;
    for(auto i:h_paths)
    {
        all_paths.push_back("h"+i);// add h to horizontal path
    }
    for(auto i:v_paths)
    {
        all_paths.push_back("v"+i);// add v to vertical paths
    }
    return all_paths;// return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string>paths=get_paths(1,1,n,m);// 1- indexing for understaing purpose
    for(string x:paths)
    {
        cout<<x<<" ";
    }
    return 0;
}