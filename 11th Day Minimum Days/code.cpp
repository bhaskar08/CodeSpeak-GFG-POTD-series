class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        int count=0;
        for(int i=1; i<N; i++)
        {
            if(S[i]==S[i-1])
            {
                count++;
            }
        }
        
        if(count==0)return 0;
        
        for(int i=0;i<N; i++)
        {
            int index=P[i];
            if(index!=0 and S[index]==S[index-1])
            {
                count--;
            }
            if(index!=N-1 and S[index]==S[index+1])
            {
                count--;
            }
            
            if(count==0)
            {
                return i+1;
            }
            S[index]='?';
        }
        
        return -1;
    }
};