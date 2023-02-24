//User function Template for C++

class Solution {
  public:
  
  vector<int> dijkstra(int source, int n, vector<pair<int,int>>adj[])
  {
      vector<int>dis(n+1,1000000001);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,source});
      
      dis[source]=0;
      
      vector<int>vis(n+1,0);
      
      while(!pq.empty())
      {
          auto node=pq.top();
          pq.pop();
          int v=node.second;
          int dis_v=node.first;
          
          if(vis[v]==1)continue;
          vis[v]=1;
          
          for(auto child:adj[v])
          {
              int child_v=child.first;
              int child_wt=child.second;
              
              if(dis[child_v]>dis[v]+child_wt)
              {
                  dis[child_v]=dis[v]+child_wt;
                  pq.push({dis[child_v],child_v});
              }
          }
      }
      
      return dis;
      
  }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0; i<m; i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            int w1=edges[i][2];
            adj[x].push_back({y,w1});
            adj[y].push_back({x,w1});
        }
        vector<int>dis_a=dijkstra(a,n,adj);
        vector<int>dis_b=dijkstra(b,n,adj);
        
        int ans=dis_a[b];
        
        for(int i=0;i<m; i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w2=edges[i][3];
            
            ans=min(ans,dis_a[u]+w2+dis_b[v]);
            ans=min(ans,dis_a[v]+w2+dis_b[u]);
        }
        
        if(ans>=1000000001)return -1;
        
        return ans;
    }
};