//User function Template for C++

class Solution{
  public:
  vector<int>vis;
  int count=0;
  bool dfs(vector<int>adj[], int i)
  {
      vis[i]=1;
      
      bool select=false;
      for(auto child:adj[i])
      {
          if(!vis[child] and !dfs(adj,child))
          {
            select=true;   
          }
      }
      
      if(select)
      {
          count++;
      }
      
      return select;
      
  }
  
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vis=vector<int>(N+1,0);
        // vector<vector<int>>adj(N+1);
        vector<int>adj[N+1];
        for(auto ele:edges)
        {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        
        dfs(adj,1);
        
        return count;
    }
};