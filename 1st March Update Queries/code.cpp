//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int n,int q,vector<vector<int>> &u)
        {
            vector <int> a(n);
            fill(a.begin(),a.end(),0);
            int dp[n][20];
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<20;j++)
                    dp[i][j]=0;
            }
            
            for(auto j:u)
            {
                for(int i=0;i<20;i++)
                {
                    if(j[2]&(1ll<<i))
                    {
                        dp[j[0]-1][i]++;
                        if(j[1]<n)
                            dp[j[1]][i]--;
                    }
                }
            }
            for(int j=0;j<20;j++)
            {
                for(int i=1;i<n;i++)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
            
            
            for(int i=0;i<n;i++)
            {
                int ans=0;
                for(int j=0;j<20;j++)
                {
                    if(dp[i][j])
                        ans+=(1<<j);
                }
                a[i]=ans;
            }
            return a;
        }
};