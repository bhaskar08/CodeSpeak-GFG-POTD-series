//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int st=0;
        int end=0;
        int ans=0;
        
        while(end!=n)
        {
            if(m>0)
            {
                if(arr[end]=='O')
                {
                    m--;
                }
            }
            else
            {
                if(arr[end]=='O')
                {
                    while(arr[st]!='O')
                    {
                        st++;
                    }
                    st++;
                }
            }
            ans=max(ans,end-st+1);
            end++;
        }
        
        return ans;
    }
};