//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        int ans=min({mp['b']/1,mp['a']/1,mp['l']/2,mp['o']/2,mp['n']/1});
        
        return ans;
    }
};