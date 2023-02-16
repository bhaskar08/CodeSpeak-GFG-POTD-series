// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        long long next_term=0;
        for(int i=0;i<K; i++)
        {
            if(i==N-1)
            {
                return GeekNum[i];
            }
            next_term+=GeekNum[i];
        }
        GeekNum.push_back(next_term);
        
        int i=0;
        int j=K;
        
        while(j!=N)
        {
            next_term-=GeekNum[i];
            next_term+=GeekNum[j];
            GeekNum.push_back(next_term);
            i++;
            j++;
        }
        
        return GeekNum[N-1];
    }
};