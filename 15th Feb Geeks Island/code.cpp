//User function Template for C++

class Solution{   
public:
    void solve(vector<vector<int>>&mat,int i, int j, vector<vector<int>>&vis, int n, int m)
    {
        if(i<0 or j<0 or i>n or j>m or vis[i][j])return;
        
        vis[i][j]=1;
        if(i>0 and mat[i-1][j]>=mat[i][j])
        {
            solve(mat,i-1,j,vis,n,m);
        }
        if(i<n-1 and mat[i+1][j]>=mat[i][j])
        {
            solve(mat,i+1,j,vis,n,m);
        }
        if(j>0 and mat[i][j-1]>=mat[i][j])
        {
            solve(mat,i,j-1,vis,n,m);
        }
        if(j<m-1 and mat[i][j+1]>=mat[i][j])
        {
            solve(mat,i,j+1,vis,n,m);
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<int>>indian(N,vector<int>(M,0));
        vector<vector<int>>arabian(N,vector<int>(M,0));
        
        for(int i=0;i<N; i++)
        {
            if(!indian[i][0])
            {
                solve(mat,i,0,indian,N,M);
            }
        }
        
        for(int j=0; j<M; j++)
        {
            if(!indian[0][j])
            {
                solve(mat,0,j,indian,N,M);
            }
        }
        
        for(int i=0;i<N; i++)
        {
            if(!arabian[i][M-1])
            {
                solve(mat,i,M-1,arabian,N,M);
            }
        }
        
        for(int j=0;j<M; j++)
        {
            if(!arabian[N-1][j])
            {
                solve(mat,N-1,j,arabian,N,M);
            }
        }
        
        int count=0;
        
        for(int i=0;i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(indian[i][j]==1 and arabian[i][j]==1)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};