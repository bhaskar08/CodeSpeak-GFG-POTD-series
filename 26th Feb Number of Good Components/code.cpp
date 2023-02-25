// User function Template for C++

class Solution {
  public:
  vector<int>vis;
  
  void dfs(int source, vector<vector<int>>&adj, int &vertex, int &edges)
  {
      vis[source]=1;
      vertex++;
      
      for(auto child: adj[source])
      {
          edges++;
          if(!vis[child])
          {
              dfs(child,adj,vertex,edges);
          }
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vis=vector<int>(V+1,0);
        
        int ans=0;
        
        for(int i=1; i<=V; i++)
        {
            if(!vis[i])
            {
                int vertex=0;
                int edges=0;
                dfs(i,adj,vertex,edges);
                edges=edges/2;
                if(edges==(vertex*(vertex-1))/2)
                {
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};