//User function Template for C++

class Solution
{
    public:
        bool isvalid(vector <int> &a,int n,int k,int w,long long int mid)
        {
            long long int ps[n];
            fill(ps,ps+n,0ll);
            long long int ans=0;
            for(long long int i=0;i<n;i++)
            {
                if(i-1>=0)
                    ps[i]+=ps[i-1];
                if(a[i]+ps[i]<mid)
                {
                    long long int e=mid-a[i]-ps[i];
                    ans+=e;
                    ps[i]+=e;
                    if(i+w<n)
                        ps[i+w]-=e;
                }
            }
            return (ans<=k);
            // for()
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            int ans=0;
            long long int l=0,h=1e14;
            while(l<=h)
            {
                long long int mid=(l+h)/2;
                if(isvalid(a,n,k,w,mid))
                {
                    l=mid+1;
                    ans=mid;
                }
                else
                {
                    h=mid-1;
                }
            }
            return ans;
        }
};