//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
      // Complete the function
      long long firstmax=LONG_MIN;
      long long secondmax=LONG_MIN;
      long long thirdmax=LONG_MIN;
      
      long long firstmin=LONG_MAX;
      long long secondmin=LONG_MAX;
      
      for(int i=0;i<n; i++)
      {
          if(arr[i]>=firstmax)
          {
              thirdmax=secondmax;
              secondmax=firstmax;
              firstmax=arr[i];
              
          }
          else if(arr[i]>=secondmax)
          {
              thirdmax=secondmax;
              secondmax=arr[i];
          }
          else if(arr[i]>=thirdmax)
          {
              thirdmax=arr[i];
          }
          
          
          if(arr[i]<=firstmin)
          {
              secondmin=firstmin;
              firstmin=arr[i];
          }
          else if(arr[i]<=secondmin)
          {
              secondmin=arr[i];
          }
          
      }
      
      
      return max(firstmax*secondmax*thirdmax, firstmin*secondmin*firstmax);
    }
};