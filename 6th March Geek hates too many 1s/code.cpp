// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int count=0;
        
        for(int i=31; i>=0; i--)
        {
            if(n & (1<<i))
            {
                count++;
            }
            else
            {
                count=0;
            }
            
            if(count==3)
            {
                n=n & (~(1<<i));
                count=0;
            }
        }
        
        return n;
    }
};