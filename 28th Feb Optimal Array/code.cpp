//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int>ans;
        //i=0;
        ans.push_back(0);
        
        for(int i=1;i<n; i++)
        {
            int new_ans=ans[i-1]+(a[i]-a[i/2]);
            ans.push_back(new_ans);
        }
        
        return ans;
        
    }
};