// User function Template for C++

class Solution {
  public:
  int countSetBit(int num)
  {
      int setBitsb=0;
      while(num)
        {
            setBitsb+=num%2;
            num/=2;
        }
        
        return setBitsb;
  }
    int minVal(int a, int b) {
        // code here

        int setBitsb=countSetBit(b);
        
        
        
        int ans=0;
        int setBitAns=setBitsb;
        for(int i=31; i>=0; i--)
        {
            if(setBitAns and (a&(1<<i)))
            {
                ans=ans | (1<<i);
                setBitAns--;
            }
        }
        
        for(int i=0;i<=31; i++)
        {
            if(setBitAns and !(a&(1<<i)))
            {
                setBitAns--;
                ans=ans | (1<<i);
            }
        }
        return ans;
    }
};
