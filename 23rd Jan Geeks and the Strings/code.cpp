class Solution {
  public:
    string removePair(string s) {
        // code here
        
        stack<char>st;

        
        for(int i=0; i<s.size(); i++)
        {
            if(!st.empty() and st.top()==s[i])
            {
                st.pop();
            }
            else 
            {
                st.push(s[i]);
            }
        }
        
        
        string ans="";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return "-1";
        
        return ans;
    }
};
