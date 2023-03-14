//User function Template for C++
class Solution{
    public:
    vector<vector<int>>dp;
    int solve(vector<int>&a, int i, int j)
    {
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int mx=INT_MIN;
        for(int index=i; index<=j; index++)
        {
            int cost=a[i-1]*a[index]*a[j+1]+solve(a,i,index-1)+solve(a,index+1,j);
            mx=max(mx,cost);
            
        }
        
        return dp[i][j]= mx;
    }
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                dp=vector<vector<int>>(N+2,vector<int>(N+2,-1));
                a.push_back(1);
                a.insert(a.begin(),1);
                return solve(a,1,N);
                
        }
};