//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int a=A;
        int b=B;
        int ans=0;
        int count=0;
        while(a>C || b>D)
        {
            if(a>C)
            {
                a/=2;
                count++;
            
            }
            if(b>D)
            {
                b/=2;
                count++;
            }
        }
        ans=count;
        count=0;
        a=B;
        b=A;
        while(a>C || b>D)
        {
            if(a>C)
            {
                a/=2;
                count++;
            
            }
            if(b>D)
            {
                b/=2;
                count++;
            }
        }
        
        ans=min(ans,count);
        
        return ans;
        
    }
};