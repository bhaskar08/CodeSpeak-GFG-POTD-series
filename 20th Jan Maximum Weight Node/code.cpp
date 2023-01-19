//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      unordered_map<int,int>mp;
      
      for(int i=0;i<N; i++)
      {
          mp[i]=0;
      }
      
      for(int i=0;i<N; i++)
      {
          if(Edge[i]!=-1)
          {
              mp[Edge[i]]+=i;
          }
      }
      int ans=-1;
      int max_weight=INT_MIN;
      for(auto ele:mp)
      {
          if(ele.second>max_weight)
          {
              ans=ele.first;
              max_weight=ele.second;
          }
          else if(max_weight==ele.second)
          {
              ans=max(ans,ele.first);
          }
      }
      
      return ans;
  }
};