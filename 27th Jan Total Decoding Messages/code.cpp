class Solution { 
 public: 
 const int N=1000000007; 
 int countWaysUtil(string s, int i, vector<int>&dp) 
 { 
     if(i<=0)return 1; 
     if(dp[i]!=-1)return dp[i]; 
     int ways=0; 
     if(s[i]>='1') 
     { 
         ways=countWaysUtil(s,i-1,dp); 
     } 
     if(s[i-1]=='1' or (s[i-1]=='2' and s[i]<'7')) 
     { 
         ways+=countWaysUtil(s,i-2,dp); 
     } 
     return dp[i]=ways%N; 
 } 
  int CountWays(string str){ 
      // Code here 
      int n=str.size(); 
      vector<int>dp(n,-1); 
       
      return countWaysUtil(str,n-1,dp)%N; 
  } 
 
};