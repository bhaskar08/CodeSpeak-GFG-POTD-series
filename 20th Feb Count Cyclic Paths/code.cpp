//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        // code here 
        
        long long int mod=1000000007;
        long long int low=1l,high=0l;
        // long long int tlow=1l,thigh=0l;
        
        
        for(int i=2;i<=N;i++)
        {   
            long long int templow=low;
            long long int temphigh=high;
            // when we try to enter O we have 3 possible paths, A-O, B-O and C-O. each of these is symmetric and thus 3*(no. of ways to enter O through A) will give the full count.
            // Now it is not essential that the step will be first. So we can say that number of ways to enter O is 3* no. of ways to enter A in previous step.
            high=(3*templow)%mod;
            
            // now when we see for the lower triangle, to enter A/B/C there are 2 ways from lower plane and 1 via O.
            // this means that to enter A we have 2 paths via B-A C-A on same plane and via O-A from upper plane.
            low=(((2*templow)%mod)+temphigh)%mod;
        }
        
        return (int)high;
        
    }
};