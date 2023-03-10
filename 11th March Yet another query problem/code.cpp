class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        unordered_map<int,int>mp;
        vector<int>freq(N,0);
        
        for(int i=N-1; i>=0; i--)
        {
            mp[A[i]]++;
            freq[i]=mp[A[i]];
        }
        
        vector<int>ans;
        
        for(auto ele: Q)
        {
            int l=ele[0];
            int r=ele[1];
            int k=ele[2];
            int count=0;
            for(int i=l; i<=r; i++)
            {
                if(freq[i]==k)
                {
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        
        return ans;
    }
};