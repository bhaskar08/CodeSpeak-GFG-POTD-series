//User function Template for C++

class Solution{   
public:
vector<vector<long long int>>dp;
long long int solve(int i, int r[], int g[], int b[], int prev)
{
    if(i<0)return 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    long long int ans=LLONG_MAX;
    
    if(prev==0)
    {
        ans=min(ans,solve(i-1,r,g,b,1)+g[i]);
        ans=min(ans,solve(i-1,r,g,b,2)+b[i]);
    }
    if(prev==1)
    {
        ans=min(ans,solve(i-1,r,g,b,0)+r[i]);
        ans=min(ans,solve(i-1,r,g,b,2)+b[i]);
    }
    if(prev==2)
    {
        ans=min(ans,solve(i-1,r,g,b,0)+r[i]);
        ans=min(ans,solve(i-1,r,g,b,1)+g[i]);
    }
    
    return dp[i][prev]=ans;
    
}
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        dp=vector<vector<long long int>>(N,vector<long long int>(3,-1));
        
        long long int ans=LLONG_MAX;
        
        for(int i=0; i<3; i++)
        {
            ans=min(ans,solve(N-1,r,g,b,i));
        }
        
        return ans;
    }
};