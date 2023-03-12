//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long ans=0;
        int totalsticks=0;
        
        int mn=INT_MAX;
        
        for(int i=0;i<N; i++)
        {
            int len=A[i];
            int units=B[i];
            
            if(units%2!=0)
            {
                units--;
            }
            
            if(units>=2)
                mn=min(mn,len);
                
                
            ans+=(len*units);
            totalsticks+=units;
        }
        
        if(totalsticks%4!=0)
        {
            ans-=(2*mn);
        }
        
        return ans;
    }
};