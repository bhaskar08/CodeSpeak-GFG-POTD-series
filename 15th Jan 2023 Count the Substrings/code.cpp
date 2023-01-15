//User function Template for C++
class Solution{
public:
  long long merge(vector<int>&prefixSum, int l, int mid, int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    int left[n1];
    int right[n2];

    for(int i=0; i<n1; i++)
    {
        left[i]=prefixSum[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        right[i]=prefixSum[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;
    long long ans=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            prefixSum[k]=left[i];
            i++;
        }
        else
        {
            prefixSum[k]=right[j];
            ans+=n1-i;
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        prefixSum[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        prefixSum[k]=right[j];
        j++;
        k++;
    }

    return ans;
}

long long countInv(vector<int>&prefixSum, int l, int r)
{
    long long res=0;
    
    if(l<r)
    {
        long long int mid=l+(r-l)/2;
        res+=countInv(prefixSum,l,mid);
        res+=countInv(prefixSum,mid+1,r);
        res+=merge(prefixSum,l,mid,r);
    }

    return res;
}


long long int inversionCount(vector<int>&prefixSum)
{
    return countInv(prefixSum,0,prefixSum.size()-1);
}


  long long countSubstring(string S){
    // code here
    vector<int>temp(S.size());
    
    for(int i=0;i<S.size(); i++)
    {
        if(S[i]=='1')temp[i]=1;
        else
        {
            temp[i]=-1;
        }
    }
    
    vector<int>prefixSum(S.size());
    
    prefixSum[0]=temp[0];
    
    
    for(int i=1;i<temp.size(); i++)
    {
        prefixSum[i]=prefixSum[i-1]+temp[i];
        
    }
    
    long long count=0;
    
    for(int i=0;i<prefixSum.size(); i++)
    {
        if(prefixSum[i]>0)count++;
    }
    
    reverse(prefixSum.begin(),prefixSum.end());
    
    long long inv=inversionCount(prefixSum);
    
    return count+inv;
  }
};