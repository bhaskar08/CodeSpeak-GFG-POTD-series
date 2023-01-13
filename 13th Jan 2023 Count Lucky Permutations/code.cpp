// User function Template for C++

class Solution {
  public:
    bool checkBit(int N, int i)
    {
        return N & (1<<i);
    }
    
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        vector<vector<long long int>>dp(N,vector<long long int>(1<<N,0));
        
        for(int i=0;i<N; i++)
        {
            dp[i][1<<i]=1;
        }
        
        vector<vector<int>>adj(N,vector<int>(N,0));
        
        for(auto ele:graph)
        {
            adj[ele[0]-1][ele[1]-1]=1;
            adj[ele[1]-1][ele[0]-1]=1;
        }
        
        for(int mask=1; mask<(1<<N); mask++)
        {
            for(int i=0;i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(j!=i and arr[j]!=arr[i] and checkBit(mask,j) and adj[arr[i]-1][arr[j]-1])
                    {
                        dp[i][mask]+=dp[j][mask ^ (1<<i)];
                    }
                }
            }
        }
        
        long long int ans=0;
        
        for(int i=0; i<N; i++)
        {
            ans+=dp[i][(1<<N)-1];
        }
        
        return ans;
    }
};