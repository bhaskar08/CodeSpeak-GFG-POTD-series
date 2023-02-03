//User function template for C++
class Solution{
public:  
  // calculate the maximum sum with out adjacent
  int findMaxSum(int *arr, int n) {
      // code here
      int a=0;
      int b=0;
      for(int i=1; i<=n; i++)
      {
          int temp=a;
          a=max(a,b);
          b=temp+arr[i-1];
      }
      
      return max(a,b);
  }
};