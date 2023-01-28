//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string,bool>mp;
    bool isScrambleUtil(string a, string b)
    {
        if(a==b)return true;
        
        if(a.size()<1 or b.size()<1)return false;
        string key=a;
        key+=" ";
        key+=b;
        if(mp.find(key)!=mp.end())return mp[key];
        bool flag=false;
        int n=a.size();
        for(int i=1; i<n; i++)
        {
            if((isScrambleUtil(a.substr(0,i),b.substr(0,i)) and isScrambleUtil(a.substr(i,n-i),b.substr(i,n-i))) or (isScrambleUtil(a.substr(0,i),b.substr(n-i,i)) and isScrambleUtil(a.substr(i,n-i),b.substr(0,n-i))))
            {
                flag=true;
                break;
            }
        }
        
        return mp[key]=flag;
        
    }
    bool isScramble(string S1, string S2){
        //code here
        if(S1==S2)return true;
        
        if(S1.size()!=S2.size())return false;
        
        return isScrambleUtil(S1,S2);
        
    }    
};
