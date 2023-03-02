//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        int k=costs[0].size();
        
        if(k<=1  and n>1)return -1;
        
        vector<vector<int>>dp(n,vector<int>(k,-1));
        
        int min1=INT_MAX;
        int min2=INT_MAX;
        
        for(int j=0; j<k; j++)
        {
            dp[0][j]=costs[0][j];
            if(costs[0][j]<min1)
            {
                min2=min1;
                min1=costs[0][j];
            }
            else if(costs[0][j]<min2)
            {
                min2=costs[0][j];
            }
        }
        
        for(int i=1; i<n; i++)
        {
            int newmin1=INT_MAX;
            int newmin2=INT_MAX;
            for(int j=0; j<k; j++)
            {
                if(min1==dp[i-1][j])
                {
                    dp[i][j]=min2+costs[i][j];
                }
                else
                {
                    dp[i][j]=min1+costs[i][j];
                }
                
                if(dp[i][j]<newmin1)
                {
                    newmin2=newmin1;
                    newmin1=dp[i][j];
                }
                else if(dp[i][j]<newmin2)
                {
                    newmin2=dp[i][j];
                }
                
                
            }
            
            min1=newmin1;
            min2=newmin2;
        }
        
        return min1;
    }
};