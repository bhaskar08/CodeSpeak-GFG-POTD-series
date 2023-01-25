//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string low;
        string up;
        
        for(int i=0;i<n; i++)
        {
            if(str[i]>='a' and str[i]<='z')
            {
                low+=str[i];
            }
            else
            {
                up+=str[i];
            }
        }
        sort(low.begin(),low.end());
        sort(up.begin(),up.end());
        
        int i=0;
        int j=0;
        int k=0;
        string ans;
        while(i<low.size() or j<up.size())
        {
            if(str[k]>='a' and str[k]<='z')
            {
                ans+=low[i];
                i++;
            }
            else
            {
                ans+=up[j];
                j++;
            }
            k++;
        }
        
        return ans;
    }
};