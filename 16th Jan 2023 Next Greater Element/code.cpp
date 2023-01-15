// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<int>st;
        st.push(n-1);
        vector<long long>ans;
        ans.push_back(-1);
        
        for(int i=n-2;i>=0; i--)
        {
            while(!st.empty() and arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans.push_back(arr[st.top()]);
            }
            else
            {
                ans.push_back(-1);
            }
            
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};