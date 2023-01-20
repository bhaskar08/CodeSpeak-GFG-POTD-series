// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int temp=b;
        int setBitsb=0;
        
        while(temp)
        {
            setBitsb+=temp%2;
            temp/=2;
        }
        
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