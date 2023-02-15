//User function Template for C++
class Solution{
public:
vector<int>vis;
    int solve(vector<int>&arr, int i)
    {
        if(i>=arr.size() or i<0)
            return 1;
            
        if(vis[i]!=-1)
        {
            return vis[i];
        }
        vis[i]=0;
        vis[i]=solve(arr,i+arr[i]);
        
        return vis[i];
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vis=vector<int>(n,-1);
        
        for(int i=0;i<n; i++)
        {
            if(vis[i]==-1)
            {
                solve(arr,i);
            }
        }
        int count=0;
        for(int i=0;i<n; i++)
        {
            if(vis[i]==1)count++;
        }
        
        return count;
    }  
};