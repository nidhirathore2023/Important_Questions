    #include<iostream>
    #include<vector>
    using namespace std;
    void get_paths(int sr,int sc,int dr,int dc,string psf)
    {
      if(sr==dr && sc==dc)//boundray condition for row and column 
      {
        cout<<psf<<" ";// print all results 
        return ;
      }
      for(int i=1;i<=dc-sc;i++)// for column moves 
      {
        get_paths(sr,sc+i,dr,dc,"h"+to_string(i)+psf);
      }
      for(int i=1;i<=dr-sr;i++)// for rows moves
      {
          get_paths(sr+i,sc,dr,dc,"v"+to_string(i)+psf);
      }
      for(int i=1;i<=dr-sr && i<=dc-sc ;i++)// for diogonal moves
      {
          get_paths(sr+i,sc+i,dr,dc,"d"+to_string(i)+psf);
      }
    }
    int main()
    {
        int n,m;
        cin>>n>>m;
        get_paths(0,0,n-1,m-1,"");
        return 0;
    }